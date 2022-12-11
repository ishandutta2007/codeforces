#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const ll inf = 1e18;

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int tt;
    cin >> tt;

    while (tt--) {
    	int n;
    	cin >> n;
    	vector<ll> a(n), b(n);
    	for (int i = 0; i < n; ++i) {
    		cin >> a[i];
    	}
    	for (int i = 0; i < n; ++i) {
    		cin >> b[i];
    	}
    	vector<ll> pref(n), suff(n);
    	pref[0] = b[0];
    	for (int i = 1; i < n; ++i) {
    		pref[i] = pref[i - 1] + b[i];
    	}
    	suff[n - 1] = a[n - 1];
    	for (int i = n - 2; i >= 0; --i) {
    		suff[i] = suff[i + 1] + a[i];
    	}

    	ll ans = inf;
    	for (int i = 0; i < n; ++i) {
    		ll x = 0;
    		if (i + 1 < n) {
    			x = suff[i + 1];
    		}
    		ll y = 0;
    		if (i - 1 >= 0) {
    			y = pref[i - 1];
    		}
    		ans = min(ans, max(x, y));
    	}
    	cout << ans << "\n";
    }

}