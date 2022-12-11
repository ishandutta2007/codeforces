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
    	int n, k;
    	cin >> n >> k;
    	vector<ll> a(n);
    	for (int i = 0; i < n; ++i) {
    		cin >> a[i];
    	}
    	vector<pair<ll, int> > sorted;
    	for (int i = 0; i < n; ++i) {
    		sorted.pb({a[i], i});
    	}
    	sort(all(sorted));
    	vector<int> pos(n);
    	for (int i = 0; i < n; ++i) {
    		pair<ll, int> p = {a[i], i};
    		pos[i] = lower_bound(all(sorted), p) - sorted.begin();
    	}
    	for (int i = 0; i < n; ++i) {
    		int place = sorted[i].second;
    		if (place == 0) {
    			continue;
    		}
    		if (pos[place - 1] != i - 1) {
    			--k;
    		}
    	}
    	cout << (k >= 1 ? "YES\n" : "NO\n");
    }

}