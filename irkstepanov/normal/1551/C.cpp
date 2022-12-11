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
    	vector<string> a(n);
    	for (int i = 0; i < n; ++i) {
    		cin >> a[i];
    	}
    	int ans = 0;
    	for (char c = 'a'; c <= 'e'; ++c) {
    		vector<int> x;
    		for (int i = 0; i < n; ++i) {
    			int val = 0;
    			for (int j = 0; j < sz(a[i]); ++j) {
    				if (a[i][j] == c) {
    					++val;
    				} else {
    					--val;
    				}
    			}
    			x.pb(val);
    		}
    		sort(all(x));
    		reverse(all(x));
    		if (x[0] <= 0) {
    			continue;
    		}
    		int cnt = 0;
    		int sum = 0;
    		for (int i = 0; i < sz(x); ++i) {
    			if (sum + x[i] > 0) {
    				++cnt;
    				sum += x[i];
    			} else {
    				break;
    			}
    		}
    		ans = max(ans, cnt);
    	}
    	cout << ans << "\n";
    }

}