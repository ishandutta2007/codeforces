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
    	int n, k;
    	cin >> n >> k;
    	vector<ll> a(n);
    	for (int i = 0; i < n; ++i) {
    		cin >> a[i];
    	}
    	ll ans = -inf;
    	for (int j = n; j >= 1; --j) {
    		ll opt = ll(j) * (j - 1);
    		if (opt < ans) {
    			break;
    		}
    		for (int i = j - 1; i >= 1; --i) {
    			opt = ll(j) * i;
    			if (opt < ans) {
    				break;
    			}
    			ans = max(ans, ll(j) * i - ll(k) * (a[i - 1] | a[j - 1]));
    		}
    	}
    	cout << ans << "\n";
    }

}