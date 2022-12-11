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

const int n = 19;
int dp[1 << n];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    vector<vector<int> > steps;
    steps.pb({0, 1, 2});
    steps.pb({3, 4, 5, 6});
    steps.pb({7, 8, 9, 10, 11});
    steps.pb({12, 13, 14, 15});
    steps.pb({16, 17, 18});

    steps.pb({0, 3, 7});
    steps.pb({1, 4, 8, 12});
    steps.pb({2, 5, 9, 13, 16});
    steps.pb({6, 10, 14, 17});
    steps.pb({11, 15, 18});

    steps.pb({7, 12, 16});
    steps.pb({3, 8, 13, 17});
    steps.pb({0, 4, 9, 14, 18});
    steps.pb({1, 5, 10, 15});
    steps.pb({2, 6, 11});

    vector<int> delta;
    for (vector<int>& v : steps) {
    	for (int lf = 0; lf < sz(v); ++lf) {
    		int mask = 0;
    		for (int rg = lf; rg < sz(v); ++rg) {
    			mask |= (1 << v[rg]);
    			delta.pb(mask);
    		}
    	}
    }
    sort(all(delta));
    delta.resize(unique(all(delta)) - delta.begin());

    dp[0] = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
    	dp[mask] = 0;
    	for (int x : delta) {
    		if (((mask & x) == x) && !dp[mask ^ x]) {
    			dp[mask] = 1;
    			break;
    		}
    	}
    }

    int mask = 0;
    char c;
    for (int i = 0; i < n; ++i) {
    	cin >> c;
    	if (c != '.') {
    		mask |= (1 << i);
    	}
    }

    cout << (dp[mask] ? "Karlsson" : "Lillebror") << "\n";

}