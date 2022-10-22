#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300;
char S[MAXN + 1][MAXN + 1];

int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        int c[3][3] = {};
        int n, tot = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%s", S[i]);
            for (int j = 0; j < n; j++)
            {
                int r = (i + j) % 3;
                if (S[i][j] == 'O')
                {
                    tot++;
                    for (int k = 0; k < 3; k++)
                        c[r][k]++;
                }
                else if (S[i][j] == 'X')
                {
                    tot++;
                    for (int k = 0; k < 3; k++)
                        c[k][r]++;
                }
            }
        }
        int ri = 0, rj = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (i != j && c[i][j] <= tot / 3)
                {
                    ri = i;
                    rj = j;
                }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                int r = (i + j) % 3;
                if (r == ri && S[i][j] == 'O')
                    S[i][j] = 'X';
                else if (r == rj && S[i][j] == 'X')
                    S[i][j] = 'O';
            }
        for (int i = 0; i < n; i++)
            puts(S[i]);
    }
    return 0;
}