// Criminal.
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 19, Mod = 1e9 + 7;
int n, m, q, A[N], C[30];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", &A[i]);
        for (int j = 0; j < 20; j ++)
            if (A[i] >> j & 1)
                C[j] ++;
    }
    long long SM = 0;
    for (int i = 1; i <= n; i ++)
    {
        int a = 0;
        for (int j = 20; ~ j; j --)
            if (C[j])
                a |= 1 << j, C[j] --;
        SM += 1LL * a * a;
    }
    printf("%lld\n", SM);
    return 0;
}