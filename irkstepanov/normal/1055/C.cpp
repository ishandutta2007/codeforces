#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll solve(ll la, ll ra, ll ta, ll lb, ll rb, ll tb) {
	ll g = __gcd(ta, tb);
	ll x = la - lb;
	ll T = min(ra - la + 1, rb - lb + 1);
	if (x % g == 0) {
		return T;
	}
	ll u = x % g;
	if (u < 0) {
		u += g;
	}
	u = x - u;
	return min(T, u + 1 - la + rb);
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll la, ra, ta;
    ll lb, rb, tb;
    cin >> la >> ra >> ta;
    cin >> lb >> rb >> tb;

    ll ans = 0;
    ans = max(ans, solve(la, ra, ta, lb, rb, tb));
    ans = max(ans, solve(lb, rb, tb, la, ra, ta));

    cout << ans << "\n";
    
    
}