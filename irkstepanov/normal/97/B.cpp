#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double ld;

vector<int> sorted;
vector<set<int> > v;

set<int> solve(int lf, int rg)
{
	if (lf == rg) {
		return v[lf];
	}
	int md = (lf + rg) >> 1;
	set<int> x = solve(lf, md);
	set<int> y = solve(md + 1, rg);
	for (int val : y) {
		v[md + 1].insert(val);
	}
	for (int val : x) {
		v[md].insert(val);
	}
	if (sz(x) < sz(y)) {
		for (int val : x) {
			v[md + 1].insert(val);
			y.insert(val);
		}
		return y;
	} else {
		for (int val : y) {
			v[md].insert(val);
			x.insert(val);
		}
		return x;
	}
}

int main()
{

	//ifstream cin("input.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	//n = 10000;
	cin >> n;

	vector<pii> a(n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		//x = y = i;
		cin >> x >> y;
		sorted.pb(x);
		a[i] = {x, y};
	}
	sort(all(sorted));
	sorted.resize(unique(all(sorted)) - sorted.begin());
	v.resize(sz(sorted));

	for (int i = 0; i < n; ++i) {
		a[i].first = lower_bound(all(sorted), a[i].first) - sorted.begin();
		v[a[i].first].insert(a[i].second);
	}

	solve(0, sz(v) - 1);

	vector<pii> ans;
	for (int i = 0; i < sz(v); ++i) {
		for (int y : v[i]) {
			ans.pb({sorted[i], y});
		}
	}

	cout << sz(ans) << "\n";
	for (int i = 0; i < sz(ans); ++i) {
		cout << ans[i].first << " " << ans[i].second << "\n";
	}

}