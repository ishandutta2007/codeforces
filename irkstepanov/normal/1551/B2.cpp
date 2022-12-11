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
    	map<int, vector<int> > mapa;
    	vector<int> pos;
    	for (int i = 0; i < n; ++i) {
    		int x;
    		cin >> x;
    		mapa[x].pb(i);
    	}
    	for (auto it : mapa) {
    		for (int j = 0; j < sz(it.second) && j < k; ++j) {
    			pos.pb(it.second[j]);
    		}
    	}
    	while (sz(pos) % k) {
    		pos.pop_back();
    	}
    	vector<int> ans(n, 0);
    	for (int i = 0; i < sz(pos); ++i) {
    		ans[pos[i]] = i % k + 1;
    	}
    	for (int i = 0; i < n; ++i) {
    		cout << ans[i] << " ";
    	}
    	cout << "\n";
    }

}