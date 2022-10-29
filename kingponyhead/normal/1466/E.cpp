// KingPonyHead
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 1e6 + 77, Mod = 1e9 + 7, LG = 60;
int n, q, C[LG];
ll A[N];
int main()
{
    scanf("%d", &q);
    while (q --)
    {
        scanf("%d", &n);
        memset(C, 0, sizeof(C));
        ll ans = 0;
        for (int i = 1; i <= n; i ++)
        {
            scanf("%lld" ,&A[i]);
            for (int j = 0; j < LG; j ++)
                if ((A[i] >> j) & 1LL)
                    C[j] ++;
        }
        for (int i = 1; i <= n; i ++)
        {
            ll sm = 0;
            ll sm2 = 0;
            for (int j = 0; j < LG; j ++)
                if ((A[i] >> j) & 1LL)
                    sm = (sm + (1LL << j) % Mod * C[j]) % Mod;
            for (int j = 0; j < LG; j ++)
            {
                if ((A[i] >> j) & 1LL)
                    sm2 = (sm2 + (1LL << j) % Mod * n) % Mod;
                else
                    sm2 = (sm2 + (1LL << j) % Mod * C[j]) % Mod;
            }
            ans = (ans + sm * sm2) % Mod;
        }
        printf("%lld\n", ans);
    }
}