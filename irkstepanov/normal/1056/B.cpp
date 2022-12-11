#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

ll get(ll n, ll a, ll m) {
	ll f;
	if (a) {
		f = a;
	} else {
		f = m;
	}
	if (f > n) {
		return 0;
	}
	ll k = (n - f) / m;
	return k + 1;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    ll ans = 0;
    for (int a = 0; a < m; ++a) {
    	for (int b = 0; b < m; ++b) {
    		int c = (a * a + b * b) % m;
    		if (c) {
    			continue;
    		}
    		ans += get(n, a, m) * get(n, b, m);
    	}
    }

    cout << ans << "\n";

}