#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll mod = 1e9+7;
ll l, r;
int main() {
    scanf("%lld %lld", &l, &r);

    ll x = 1;
    ll lf, rf;
    for (ll i=0; i<62; i++) {
        if (x <= l-1 && l-1 < 2*x) lf = i+1;
        if (x <= r && r < 2*x) rf = i+1;
        x *= 2;
    }

    if (l==1) lf = 0;

    ll l1, l2, r1, r2;
    if (lf%2==0) {
        l1 = ((1LL<<lf)-1)/3;
        l2 = (l-1)-l1;
    }
    else {
        l2 = 2*((1LL<<(lf-1))-1)/3;
        l1 = (l-1)-l2;
    }

    if (rf%2==0) {
        r1 = ((1LL<<rf)-1)/3;
        r2 = r-r1;
    }
    else {
        r2 = 2*((1LL<<(rf-1))-1)/3;
        r1 = r-r2;
    }
    ll ans;
    ans = (r1%mod)*(r1%mod)%mod;
    ans = (ans + (r2%mod)*(r2%mod+1)%mod)%mod;
    ans = (mod+ans - (l1%mod)*(l1%mod)%mod)%mod;
    ans = (mod+ans - (l2%mod)*(l2%mod+1)%mod)%mod;

    printf("%lld", ans);

}