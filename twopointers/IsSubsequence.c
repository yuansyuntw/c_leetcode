// 1. create a dp table.
// 2. find the top-left result.

bool isSubsequence(char *s, char *t)
{
    int lengthOfS = strlen(s);
    int lengthOfT = strlen(t);

    bool result = true;
    int lastFindSPosition = lengthOfT;
    for (int col = lengthOfS - 1; col >= 0; col--)
    {
        bool isNotFindEqual = true;
        for (int row = lastFindSPosition - 1; row >= 0; row--)
        {
            bool isEqual = (s[col] == t[row]);
            if (isEqual)
            {
                if (isNotFindEqual)
                {
                    lastFindSPosition = row;
                }
                isNotFindEqual = false;
            }
        }
        if (isNotFindEqual)
        {
            result = false;
            break;
        }
        else
        {
            if (col == 0)
            {
                break;
            }
        }
    }

    return result;
}
