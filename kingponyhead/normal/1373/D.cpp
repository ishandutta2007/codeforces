// Screw this ..
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 1e6 + 9, Mod = 1e9 + 7;
int n, q, m, A[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    scanf("%d", &q);
    for (; q; q --)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i ++)
            scanf("%d", &A[i]);
        long long SM = 0;
        for (int i = 0; i < n; i += 2)
            SM += A[i];
        long long best = 0;
        long long Mx[2] = {-(ll)1e18, -(ll)1e18};
        for (int i = 0; i < n; i ++)
        {
            int val = (i & 1) ? A[i] : -A[i];
            Mx[0] += val;
            Mx[1] += val;
            Mx[0] = max(Mx[0], (ll)val);
            best = max(best, Mx[1]);
            swap(Mx[0], Mx[1]);
        }
        printf("%lld\n", best + SM);
    }
    return 0;
}