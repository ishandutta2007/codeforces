#include <bits/stdc++.h>

using namespace std;

int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", 2);
        if (n == 2)
            printf("%d %d\n", 1, 2);
        bool fl = 0;
        while (n > 2)
        {
            printf("%d %d\n", n, n - 2);
            if (!fl)
            {
                printf("%d %d\n", n - 1, n - 1);
                fl = 1;
            }
            n--;
        }
    }
    return 0;
}