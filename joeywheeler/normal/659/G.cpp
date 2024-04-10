#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007ll

using namespace std;

typedef long long ll;

ll f[2][1000005];
ll h[1000005];
int n;

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%lld", h+i);
    ll res = 0;
    FO(i,1,n+1) {
        // 1 means we are da first
        ll mx = h[i-1]-1;
        f[1][i] = h[i-1]-1;
        if (i != 1) {
            if (h[i-1] >= h[i-2]) {
                ll mn = h[i-1]-h[i-2]+1;
                f[1][i] += (mx-mn+1)*f[0][i-1];
            } else {
                ll mn = 1;
                f[1][i] += (mx-mn+1)*f[0][i-1];
            }
        }
        f[1][i] %= MOD;
        res += f[1][i];
        //printf("f[1][%d]=%lld\n", i, f[1][i]);
        if (i != n) {
            // 0 means we are not da first
            ll mn = h[i-1] >= h[i] ? h[i-1]-h[i]+1 :
                1;
            f[0][i] += mx-mn+1;
            if (i != 1) {
                if (h[i-1] >= h[i-2]) {
                    ll MN = max(mn,h[i-1]-h[i-2]+1);
                    f[0][i] += (mx-MN+1)*f[0][i-1];
                } else {
                    f[0][i] += (mx-mn+1)*f[0][i-1];
                }
            }
        }
        f[0][i] %= MOD;
        //printf("f[0][%d]=%lld\n", i, f[0][i]);
    }
    printf("%lld\n", res % MOD);
}