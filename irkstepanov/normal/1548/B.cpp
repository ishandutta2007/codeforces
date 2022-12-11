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
    	vector<ll> a(n);
    	for (int i = 0; i < n; ++i) {
    		cin >> a[i];
    	}
    	vector<ll> d;
    	for (int i = 1; i < n; ++i) {
    		d.pb(abs(a[i] - a[i - 1]));
    	}
    	n = sz(d);
    	if (n == 0) {
    		cout << "1\n";
    		continue;
    	}
    	vector<ll> suff(n);
    	suff[n - 1] = d[n - 1];
    	for (int i = n - 2; i >= 0; --i) {
    		suff[i] = __gcd(d[i], suff[i + 1]);
    	}
    	int ans = 0;
    	for (int i = 0; i < n; ++i) {
    		if (suff[i] > 1) {
    			ans = max(ans, n - i);
    		}
    	}

    	vector<int> pos;
    	pos.pb(n - 1);
    	for (int i = n - 2; i >= 0; --i) {
    		vector<int> nx;
    		nx.pb(i);
    		ll g = d[i];
    		for (int j : pos) {
    			ll h = __gcd(g, d[j]);
    			if (h != g) {
    				nx.pb(j);
    				g = h;
    			}
    		}
    		pos = nx;
    		//cout << i << " " << sz(pos) << endl;
    		ans = max(ans, pos.back() - i);
    	}
    	cout << ans + 1 << "\n";
    }

}