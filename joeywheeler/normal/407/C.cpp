#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define MOD 1000000007ll

using namespace std;

typedef long long ll;

ll f[105];
ll fi[105];

ll polys[100005][105];
ll a[100005];
ll currp[105];

pair<int,int> pu[100005], pp[100005];
int pus, pps;

ll fix(ll a) {
    return ((a%MOD)+MOD)%MOD;
}

ll pow(ll a, int b) {
    ll r = 1;
    while (b) {
        if (b&1) r = (r*a)%MOD;
        a = (a*a)%MOD;
        b /= 2;
    }
    return r;
}

ll inv(ll x) {
    return pow(x, MOD-2);
}

ll choose(ll a, ll b) {
    return (((f[a] * fi[b]) % MOD) * fi[a-b]) % MOD;
}

void topoly(ll r[105], ll a, ll b) {
    // convert (x+a) C b to a polynomial in x
    ll p = 1;
    for (int i = b; i >= 0; i--) {
        r[i] = fix(choose(b, i) * p);
        p = fix(p * fix(a-(b-i)));
    }
    FO(i,0,b+1) r[i] = fix(r[i] * fi[b]);
}

int main() {
    f[0] = 1;
    FO(i,1,105) {
        f[i] = (f[i-1] * i) % MOD;
    }
    FO(i,0,105) {
        fi[i] = inv(f[i]);
    }

    int n, m;
    scanf("%d %d", &n, &m);
    FO(i,0,n) scanf("%d", &a[i]);
    FO(i,0,m) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        //printf("k=%d\n", k);
        l--; r--;
        topoly(polys[i], fix(-l+k), k);
        //printf("polys[%d]=", i);
        //printf("\n");
        pu[pus++] = make_pair(l,i);
        pp[pps++] = make_pair(r+1,i);
    }
    sort(pu, pu+pus);
    sort(pp, pp+pps);
    int pui=0, ppi=0;
    FO(i,0,n) {
        while (pui < pus && pu[pui].first <= i) {
            FO(j,0,105) {
                currp[j] += polys[pu[pui].second][j];
                currp[j] = fix(currp[j]);
            }
            pui++;
        }
        while (ppi < pps && pp[ppi].first <= i) {
            FO(j,0,105) {
                currp[j] -= polys[pp[ppi].second][j];
                currp[j] = fix(currp[j]);
            }
            ppi++;
        }
        ll v = a[i];
        ll p = 1;
        FO(j,0,105) {
            v = fix(v + p * currp[j]);
            p = fix(p * fix(i-j));
        }
        printf("%d ", (int)v);
    }
    printf("\n");

    return 0;
}