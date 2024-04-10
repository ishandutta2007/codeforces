#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;
ll x[200005];
ll sm[200005];
int n;

bool cmp(ll a, ll b, ll c, ll d){
    if (a < 0 || b < 0) return false;
    return a*d > b*c; // a/b > c/d
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%lld", x+i);
    sort(x,x+n);
    FO(i,0,n) sm[i+1] = sm[i]+x[i];
    long long bnm = 0, bdnm = 1;
    int bi = 0, br = 0;
    FO(i,0,n) {
        ll med = x[i];
        // max mean?
        int s = 1, e = min(i,n-i-1), b = 0;
        while (s <= e) {
            int md = (s+e)/2;
            // take md vs take md-1?
            ll s1 = sm[i]-sm[i-md] + sm[n]-sm[n-md] + x[i];
            if (cmp(s1-(2*md+1)*med,2*md+1,bnm,bdnm)) {
                bi = i;
                br = md;
                bnm = s1-(2*md+1)*med;
                bdnm  = 2*md+1;
            }
            ll s2 = sm[i]-sm[i-(md-1)] + sm[n]-sm[n-(md-1)] + x[i];
            if (cmp(s1,2*md+1,s2,2*md-1)) {
                b = md;
                s = md+1;
            } else {
                e = md-1;
            }
        }
    }
    printf("%d\n", 2*br+1);
    printf("%lld ", x[bi]);
    FO(i,0,br) {
        printf("%lld %lld ", x[bi-i-1], x[n-i-1]);
    }
    printf("\n");
}