#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
bool F[MAXN + 1];

int main()
{
    F[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        F[i] = (i >= 3 && F[i - 3]) || (i >= 5 && F[i - 5]) || (i >= 7 && F[i - 7]);
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        int n;
        scanf("%d", &n);
        if (!F[n])
            puts("-1");
        else
        {
            int c[3] = {0};
            while (n)
            {
                if (F[n - 3])
                {
                    c[0]++;
                    n -= 3;
                }
                else if (F[n - 5])
                {
                    c[1]++;
                    n -= 5;
                }
                else
                {
                    c[2]++;
                    n -= 7;
                }
            }
            printf("%d %d %d\n", c[0], c[1], c[2]);
        }
    }
    return 0;
}