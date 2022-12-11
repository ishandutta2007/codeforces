#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

struct edge
{
	int from, to;
	int type;
};

vector<vector<edge> > g;
vector<int> color;
bool ok = true;

void dfs(int v, int c)
{
	color[v] = c;
	for (edge& e : g[v]) {
		if (e.type == 0) {
			if (color[e.to] == -1) {
				dfs(e.to, c);
			} else if (color[e.to] == 1 - c) {
				ok = false;
			}
		} else {
			if (color[e.to] == -1) {
				dfs(e.to, 1 - c);
			} else if (color[e.to] == c) {
				ok = false;
			}
		}
	}
}

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int k, n;
	cin >> k >> n;

	vector<vector<int> > v(k);
	vector<int> state(k);
	for (int i = 0; i < k; ++i) {
		cin >> state[i];
	}

	for (int i = 0; i < n; ++i) {
		int s;
		cin >> s;
		while (s--) {
			int x;
			cin >> x;
			--x;
			v[x].pb(i);
		}
	}

	g.resize(n);
	for (int i = 0; i < k; ++i) {
		assert(sz(v[i]) == 2);
		if (state[i] == 1) {
			g[v[i][0]].pb({v[i][0], v[i][1], 0});
			g[v[i][1]].pb({v[i][1], v[i][0], 0});
		} else {
			g[v[i][0]].pb({v[i][0], v[i][1], 1});
			g[v[i][1]].pb({v[i][1], v[i][0], 1});
		}
	}

	color.assign(n, -1);
	for (int i = 0; i < n; ++i) {
		if (color[i] == -1) {
			dfs(i, 0);
		}
	}

	cout << (ok ? "YES\n" : "NO\n");

}