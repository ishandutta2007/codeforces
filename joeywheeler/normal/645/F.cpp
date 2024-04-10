#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007ll
#define M 1000005

using namespace std;

typedef long long ll;

ll pwmd(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b&1) r = r*a%MOD;
        a = a*a%MOD;
        b/=2;
    }
    return r;
}

vector<int> f[M];
int nck[200005];
int n, k, q;

int c[M];
int v[M];
int dta[M];

void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void sub(int &a, int b) {
    a -= b;
    if (a < 0) a += MOD;
}

int main() {
    scanf("%d%d%d", &n, &k, &q);
    FO(i,0,k) nck[i] = 0;
    nck[k] = 1;
    FO(i,k+1,200005) {
        nck[i] = nck[i-1] * 1ll * i % MOD * pwmd(i-k, MOD-2) % MOD;
        //if (i <= 10) printf("%d C %d = %d\n", i, k, nck[i]);
    }
    FO(i,0,n) {
        int x;
        scanf("%d", &x);
        c[x]++;
    }
    for (int i = 1; i < M; i++) {
        f[i].push_back(i);
        for (int j = 2*i; j < M; j += i) {
            c[i] += c[j];
            f[j].push_back(i);
        }
        //printf("c[%d]=%d\n", i, c[i]);
    }
    FO(i,0,M) reverse(f[i].begin(),f[i].end());
    FO(i,1,M) v[i] = nck[c[i]];
    for (int i = M-1; i >= 1; i--) {
        for (int j = 2*i; j < M; j += i) {
            sub(v[i],v[j]);
        }
    }
    long long cres = 0;
    FO(i,1,M) {
        cres = (cres+i*1ll*v[i])%MOD;
    }
    //printf("%lld\n", cres);
    FO(z,0,q) {
        int x; scanf("%d", &x);
        for (int i : f[x]) {
            c[i]++;
            dta[i] = nck[c[i]];
            sub(dta[i], nck[c[i]-1]);
        }
        for (int i : f[x]) for (int j : f[i]) if (i != j) {
            sub(dta[j], dta[i]);
        }
        for (int i : f[x]) {
            cres += dta[i]*1ll*i;
            if (cres >= MOD*MOD) cres -= MOD*MOD;
        }
        cres %= MOD;
        printf("%lld\n", cres);
    }
}