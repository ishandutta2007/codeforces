#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;
int n; ll k;
ll a[100005];
ll b[100005];

int main() {
    scanf("%d%lld", &n, &k);
    FO(i,0,n) scanf("%lld", a+i);
    FO(i,0,n) scanf("%lld", b+i);
    ll s = 1, e = 2.5e9;
    while (s <= e) {
        ll md = (s+e)/2;
        ll tk = 0;
        FO(i,0,n) {
            ll rq = a[i]*md;
            ll nd = max(rq-b[i],0ll);
            tk += nd;
            tk = min(tk, k+1);
        }
        if (tk <= k) {
            s = md+1;
        } else {
            e = md-1;
        }
    }
    printf("%lld\n", s-1);
}