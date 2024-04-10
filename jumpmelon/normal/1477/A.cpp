#include <bits/stdc++.h>

using namespace std;

typedef long long big;

big gcd(big a, big b)
{
    while (a)
    {
        big t = b % a;
        b = a;
        a = t;
    }
    return b;
}

const int MAXN = 200000;
big X[MAXN];

int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        int n;
        big k;
        scanf("%d%lld", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%lld", &X[i]);
        sort(X, X + n);
        n = unique(X, X + n) - X;
        if (n == 1)
            puts(k == X[0] ? "YES" : "NO");
        else
        {
            cerr << n << endl;
            big g = X[1] - X[0];
            for (int i = 2; i < n; i++)
                g = gcd(g, X[i] - X[0]);
            puts((k - X[0]) % g == 0 ? "YES" : "NO");
        }
    }
    return 0;
}