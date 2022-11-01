#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;
#define MOD 1000000007ll

vector<int> v[100005], l, sm[1<<12];
int c[100005], p[100005], ip[100005];
int f[20];
bool s[100005];
int n, k;

void calc(int i) {
    v[i][0] = 1;
    v[i][1] = i;
    FO(j,2,sz(v[i])) v[i][j] = (i * (v[i][j-1] + (j-1) * 1ll * v[i][j-2])) % MOD;
}

ll ans = 0;

void go(int m, int cr, bool r2) {
    if (m == 0) {
        if (r2) ans += cr;
        else ans += 1;
        if (ans >= MOD) ans -= MOD;
    } else {
        int t = 1<<__builtin_ctz(m);
        for (int st : sm[m^t]) {
            int gc = st|t;
            int nm = m^gc;
            int os = 0;
            int ml = 0;
            long long nr = cr;
            while (gc) {
                int ind = __builtin_ctz(gc);
                os += l[ind];
                gc ^= 1<<ind;
                ml++;
            }

            c[os]++;
            nr = (nr * v[os][c[os]])%MOD;
            nr = (nr * f[ml-1]) % MOD;
            go(nm, nr, r2 || (os > 2));
            c[os]--;
        }
    }
}

ll pw(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b&1) r = (r*a)%MOD;
        a = (a*a)%MOD;
        b/= 2;
    }
    return r;
}

ll inv(ll x) {
    return pw(x,MOD-2);
}

int main() {
    scanf("%d%d", &n, &k);

    f[0] = 1;
    FO(i,1,20) f[i] = (f[i-1]*1ll*i)%MOD;
    FO(i,0,1<<k) {
        FO(j,0,1<<k) if ((i&j) == j) {
            sm[i].push_back(j);
        }
    }

    FO(i,1,n+1) {
        scanf("%d", p+i);
        if (p[i]) ip[p[i]] = i;
    }
    FO(i,1,n+1) if (!ip[i]) {
        int r = 0;
        for (int j = i; j; j = p[j]) {
            s[j] = true;
            r++;
        }
        l.push_back(r);
    }
    assert(sz(l) == k);
    FO(i,1,n+1) if (!s[i]) {
        int r = 0;
        for (int j = i; !s[j]; j = p[j]) {
            s[j] = true;
            r++;
        }
        c[r]++;
    }
    ll res = 1;
    bool r2 = false;
    FO(i,1,n+1) {
        v[i].resize(c[i]+13);
        calc(i);
        res = (res * v[i][c[i]]) % MOD;
        r2 |= c[i] && i > 2;
        for (int j = sz(v[i])-1; j >= 1; j--) {
            v[i][j] = (v[i][j]*1ll*inv(v[i][j-1]))%MOD;
        }
    }
    go((1<<k)-1,res,r2);
    printf("%lld\n", ans);
}