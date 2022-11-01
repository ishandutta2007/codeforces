#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007ll

using namespace std;

typedef long long ll;

int n;
ll nv[1000005];
ll sv[1000005];
ll svv[1000005];
int cnt[1000005];

ll pw(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b&1) r = r * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return r;
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        int x; scanf("%d", &x);
        cnt[x]++;
    }
    FO(x,0,1000000) {
        nv[x] = pw(2, cnt[x]);
        if (cnt[x] >= 1) {
            sv[x] = pw(2, cnt[x]-1) * cnt[x] % MOD * x % MOD;
        }
        if (cnt[x] >= 2) {
            svv[x] = pw(2, cnt[x]-2) * cnt[x] % MOD * (cnt[x]+1) % MOD * x % MOD * x % MOD;
        } else if (cnt[x] == 1) {
            svv[x] = x * 1ll * x % MOD;
        }
    }
    ll p10 = 1;
    FO(_,0,6) {
        FO(i,0,1000000) if (i/p10 % 10 == 0) {
            ll anv = 1, asv = 0, asvv = 0;
            for (int j = 9; j >= 0; j--) {
                int ij = i+j*p10;
                asvv = (svv[ij] * anv + asvv * nv[ij] + 2 * asv * sv[ij]) % MOD;
                asv = (sv[ij] * anv + asv * nv[ij]) % MOD;
                anv = (nv[ij] * anv) % MOD;

                nv[ij] = anv;
                sv[ij] = asv;
                svv[ij] = asvv;
            }
        }
        p10 *= 10;
    }
    p10 = 1;
    FO(_,0,6) {
        FO(i,0,1000000) if (i/p10 % 10 == 0) {
            FO(j,0,9) {
                int ij = i+j*p10;
                svv[ij] = (svv[ij]+MOD-svv[ij+p10]) % MOD;
            }
        }
        p10 *= 10;
    }

    ll res = 0;
    FO(i,0,1000000) {
        res ^= svv[i] * i;
    }
    printf("%lld\n", res);
}