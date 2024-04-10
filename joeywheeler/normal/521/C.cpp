#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007ll

using namespace std;

typedef long long ll;

ll pw(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b&1) r = (r * a) % MOD;
        a = (a*a) % MOD;
        b >>= 1;
    }
    return r;
}

ll inv(ll a) {
    return pw(a,MOD-2);
}

ll F[100005], IF[100005];

void pre() {
    F[0] = IF[0] = 1;
    FO(i,1,100005) {
        F[i] = (F[i-1] * i) % MOD;
        IF[i] = inv(F[i]);
    }
}

ll choose(int a, int b) {
    if (b > a) return 0;
    if (b < 0) return 0;
    return (((F[a] * IF[a-b]) % MOD) * IF[b]) % MOD;
}

ll v[100005];
int n, k;

char buf[100005];

int main() {
    pre();

    scanf("%d %d", &n, &k);
    scanf(" %s", buf);
    /*if (k == 0) {
        ll res = 0;
        FO(i,0,n) {
            res += (buf[i]-'0') * pw(10,n-1-i);
            res %= MOD;
        }
        printf("%lld\n", res);
        return 0;
    }*/
    FO(j,1,100005) {
        v[j] = v[j-1];
        v[j] += ((choose(n-1-j, k-1) * pw(10,j-1)) % MOD);
        v[j] %= MOD;
    }
    ll res = 0;
    for (int i = n-1; i >= 0; i--) {
        int l = n-1-i;
        int dig = buf[i]-'0';
        if (dig != 0) {
            res += v[l] * dig;
            res %= MOD;
            res += ((choose(n-1-l, k) * pw(10,l)) % MOD) * dig;
            res %= MOD;
        }
    }
    printf("%lld\n", res);
}