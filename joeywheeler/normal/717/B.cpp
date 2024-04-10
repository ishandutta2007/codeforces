#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define K 40

using namespace std;

typedef long long ll;
int n;
ll c0, c1;

ll f[K];

long double chsfp(ll a, int b) {
    if (a < b) return 0;
    long double lg = 0;
    FO(i,0,b) lg += log((long double)a-i) - log((long double)i+1);
    return exp(lg);
}

long long gn(ll x) {
    FO(i,0,K) {
        // take i of c1
        ll nx = x - i*c1;
        // n0 * c0 <= nx
        // n0 <= nx / c0
        ll n0 = nx >= 0 ? nx / c0 : -1;
        f[i] = n0;
    }
    long double fpres = 0;
    FO(i,1,K) {
        fpres += chsfp(f[i]+i,i);
        fpres += chsfp(f[i-1]+i,i) - chsfp(f[i]+i,i);
    }
    if (fpres > 1e10) return 1e10;
    else return (long long) (fpres + 0.5);
}

ll stk[10000000];
int ss;

int main() {
    scanf("%d %lld %lld", &n, &c0, &c1);
    if (c1 < c0) swap(c1,c0);
    // c0 <= c1
    //printf("%lld %lld\n", c0, c1);
    if (c0 == 0) {
        printf("%lld\n", (n-1)*c1);
        return 0;
    }
    ll sx = 0, ex = 1e10, bx = 1e10;
    while (sx <= ex) {
        ll mx = (sx+ex)/2;
        long long m = gn(mx);
        if (m >= n) {
            ex = mx-1;
            bx = mx;
        } else {
            sx = mx+1;
        }
    }
    //printf("bx=%lld\n", bx);
    stk[ss++] = 0;
    ll res = 0;
    int nmtk = 0;
    while (ss) {
        ll f = stk[--ss];

        ll a = f+c0, b = f+c1;
        if (a < bx) stk[ss++] = a;
        else {
            res += a;
            nmtk++;
        }
        if (b < bx) stk[ss++] = b;
        else {
            res += b;
            nmtk++;
        }
    }
    while (nmtk < n) {
        res -= bx;
        res += bx+c0;
        res += bx+c1;
        nmtk++;
    }

    printf("%lld\n", res);
}