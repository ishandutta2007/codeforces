#include <bits/stdc++.h>

#define FO(i,a,b) for (int i=a;i<b;i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int n, s, e;
ll x[5005];
ll a[5005];
ll b[5005];
ll c[5005];
ll d[5005];

ll cache[2][2505][2][2];

ll f(int i, int nb, int nr, int nl) {
    if (nr > 1 || nl > 1 || nb >= min(i,n-i)+3 ||
            nb < 0 || nr < 0 || nl < 0) return 1e16;
    if (i == n) {
        return nb == 0 && nr == 0 && nl == 0 ?  0 : 1e16;
    }

    ll &ans = cache[i&1][nb][nr][nl];
    if (ans != -1) return ans;

    ll dv = 0;
    if (i != 0) dv += (2*nb + nr + nl) * (x[i]-x[i-1]);

    ll res = 1e16;
    if (i != s && i != e) {
        // bounce left
        if (nb >= 2 || nb && nr || nb && nl)
            res = min(res,
                    f(i+1, nb-1, nr, nl) + a[i]+c[i]);

        if (nr && nl)
            res = min(res,
                    f(i+1, nb, nr-1, nl-1) + a[i]+c[i]);

        // bounce right
        res = min(res, f(i+1, nb+1, nr, nl) + b[i]+d[i]);

        // bounce l to r
        if (nb || nr)
            res = min(res,
                    f(i+1, nb, nr, nl) + a[i]+d[i]);

        // bounce r to l
        if (nb || nl)
            res = min(res,
                    f(i+1, nb, nr, nl) + b[i]+c[i]);
    }

    if (i == s) {
        // take off left
        if (nl) {
            res = min(res,
                    f(i+1, nb, nr, nl-1) + c[i]);
        }

        if (nb) {
            res = min(res,
                    f(i+1, nb-1, nr+1, nl) + c[i]);
        }

        // take off right
        res = min(res,
                f(i+1, nb, nr+1, nl) + d[i]);
    }

    if (i == e) {
        // end from left
        if (nr) {
            res = min(res,
                    f(i+1, nb, nr-1, nl) + a[i]);
        }
        if (nb) {
            res = min(res,
                    f(i+1, nb-1, nr, nl+1) + a[i]);
        }
        
        // end from right
        res = min(res,
                f(i+1, nb, nr, nl+1) + b[i]);
    }

    res += dv;
    return ans = res;
}

int main() {
    scanf("%d %d %d", &n, &s, &e);
    s--; e--;
    FO(i,0,n) scanf("%lld", x+i);
    FO(i,0,n) scanf("%lld", a+i);
    FO(i,0,n) scanf("%lld", b+i);
    FO(i,0,n) scanf("%lld", c+i);
    FO(i,0,n) scanf("%lld", d+i);

    for (int i = n-1; i >= 0; i--) {
        memset(cache[i&1], -1, sizeof cache[i&1]);
        FO(j,0,min(i,n-i)+3) FO(k,0,2) FO(l,0,2) f(i,j,k,l);
    }

    printf("%lld\n", f(0, 0, 0, 0));
}