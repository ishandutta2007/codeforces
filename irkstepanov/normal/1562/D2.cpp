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
    	int n, q;
    	cin >> n >> q;
    	string s;
    	cin >> s;
    	vector<int> a(n);
    	for (int i = 0; i < n; ++i) {
    		if (s[i] == '+') {
    			a[i] = 1;
    		} else {
    			a[i] = -1;
    		}
    		if (i & 1) {
    			a[i] *= (-1);
    		}
    	}
    	vector<int> pref(n);
    	pref[0] = a[0];
    	vector<pii> pairs;
    	pairs.pb({0, a[0]});

    	for (int i = 1; i < n; ++i) {
    		pref[i] = pref[i - 1];
    		pref[i] += a[i];
    		pii p = {pref[i - 1], pref[i]};
    		pairs.pb(p);
    	}

    	sort(all(pairs));
    	pairs.resize(unique(all(pairs)) - pairs.begin());

    	vector<int> type(n);
    	for (int i = 0; i < n; ++i) {
    		pii p;
    		if (i == 0) {
    			p = {0, pref[0]};
    		} else {
    			p = {pref[i - 1], pref[i]};
    		}
    		type[i] = lower_bound(all(pairs), p) - pairs.begin();
    	}

    	vector<vector<int> > lst(sz(pairs));
    	for (int i = 0; i < n; ++i) {
    		lst[type[i]].pb(i);
    	}

    	while (q--) {
    		int l, r;
    		cin >> l >> r;
    		--l, --r;
    		int s = pref[r];
    		if (l) {
    			s -= pref[l - 1];
    		}
    		if (s == 0) {
    			cout << "0\n";
    		} else {
    			int z = abs(s);
    			vector<int> ans;
    			if (z % 2 == 0) {
    				ans.pb(r);
    				--r;
    				s = pref[r];
    				if (l) {
    					s -= pref[l - 1];
    				}
    				z = abs(s);
    			}

    			pii p;

    			if (s > 0) {
    				p.second = pref[r] - s / 2;
    				p.first = p.second - 1;
    			} else {
    				p.second = pref[r] - s / 2;
    				p.first = p.second + 1;
    				//cout << pref[r] << " " << p.first << " " << p.second << endl;
    			}

    			int pos = lower_bound(all(pairs), p) - pairs.begin();
				int val = upper_bound(all(lst[pos]), r) - lst[pos].begin();
				--val;
				val = lst[pos][val];
				vector<int> nx = {val};
				for (int x : ans) {
					nx.pb(x);
				}
				ans = nx;			

    			cout << sz(ans) << "\n";
    			for (int x : ans) {
    				cout << x + 1 << " ";
    			}
    			cout << "\n";
    		}
    	}
    }

}