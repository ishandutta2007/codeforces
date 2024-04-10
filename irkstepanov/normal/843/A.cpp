#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

vector<vector<int> > g;
vector<char> used;
vector<vector<int> > comps;

void dfs(int v) {
	used[v] = true;
	comps.back().pb(v);
	for (int to : g[v]) {
		if (!used[to]) {
			dfs(to);
		}
	}
}

int main() {

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

	int n;
	cin >> n;

	vector<pii> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(all(a));

	g.resize(n);
	for (int i = 0; i < n; ++i) {
		if (a[i].second != i) {
			g[i].pb(a[i].second);
			g[a[i].second].pb(i);
		}
	}

	used.assign(n, false);
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			comps.pb(vector<int>());
			dfs(i);
		}
	}

	cout << sz(comps) << "\n";
	for (int i = 0; i < sz(comps); ++i) {
		cout << sz(comps[i]) << " ";
		for (int x : comps[i]) {
			cout << x + 1 << " ";
		}
		cout << "\n";
	}

}