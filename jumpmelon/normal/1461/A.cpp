#include <bits/stdc++.h>

using namespace std;

int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        int n;
        scanf("%d%*d", &n);
        for (int i = 0; i < n; i++)
            putchar('a' + i % 3);
        putchar('\n');
    }
    return 0;
}