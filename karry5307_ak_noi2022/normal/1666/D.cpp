#include <cstdio>
#include <cstring>
using namespace std;
int n, cnts[200], cntt[200];
char s[35], t[35];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s%s", s + 1, t + 1);
        int lens = strlen(s + 1);
        int lent = strlen(t + 1);
        for (int j = 'A'; j <= 'Z'; j++)
            cnts[j] = cntt[j] = 0;
        for (int j = 1; j <= lens; j++)
        {
            cnts[s[j]]++;
        }
        for (int j = 1; j <= lent; j++)
        {
            cntt[t[j]]++;
        }
        for (int j = 1; j <= lens; j++)
        {
            if (cnts[s[j]] > cntt[s[j]])
            {
                cnts[s[j]]--;
                s[j] = 0;
            }
        }
        bool flag = true;
        for (int j = 'A'; j <= 'Z'; j++)
        {
            if (cnts[j] != cntt[j])
                flag = false;
        }
        int nows = 1;
        for (int j = 1; j <= lent; j++)
        {
            while (nows <= lens && s[nows] == 0)
                nows++;
            if (s[nows] != t[j])
            {
                flag = false;
                break;
            }
            nows++;
        }
        printf(flag ? "YES\n" : "NO\n");
    }
}