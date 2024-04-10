#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

map<multiset<int>, int> types;

vector<vector<int> > g;
vector<multiset<int> > m;
map<int, int> curr;
vector<int> type;
int cnt = 1;

int dfs0(int v, int p)
{
	for (int to : g[v]) {
		if (to != p) {
			m[v].insert(dfs0(to, v));
		}
	}
	if (types.count(m[v])) {
		type[v] = types[m[v]];
		++curr[type[v]];
		return type[v];
	} else {
		types[m[v]] = cnt++;
		++curr[cnt - 1];
		type[v] = cnt - 1;
		return cnt - 1;
	}
}

int bestV, bestAns;

void add(int v)
{
	++curr[v];
}

void rem(int v)
{
	--curr[v];
	if (curr[v] == 0) {
		curr.erase(v);
	}
}

void dfs1(int v, int p)
{
	set<int> used;
	for (int to : g[v]) {
		if (to != p) {
			if (used.count(type[to])) {
				continue;
			}
			used.insert(type[to]);
			multiset<int>::iterator it = m[v].find(type[to]);
			int oldToType = type[to];
			int oldVType = type[v];
			rem(type[v]);
			rem(type[to]);
			m[v].erase(it);
			if (types.count(m[v])) {
				type[v] = types[m[v]];
			} else {
				types[m[v]] = cnt++;
				type[v] = cnt - 1;
			}
			m[to].insert(type[v]);
			if (types.count(m[to])) {
				type[to] = types[m[to]];
			} else {
				types[m[to]] = cnt++;
				type[to] = cnt - 1;
			}
			add(type[to]);
			add(type[v]);
			if (sz(curr) > bestAns) {
				bestV = to;
				bestAns = sz(curr);
			}
			dfs1(to, v);
			rem(type[to]);
			rem(type[v]);
			it = m[to].find(type[v]);
			m[to].erase(it);
			type[to] = oldToType;
			m[v].insert(type[to]);
			type[v] = oldVType;
			add(type[to]);
			add(type[v]);
		}
	}
}

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("ok");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	types[{}] = 0;

	g.resize(n);
	m.resize(n);
	type.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		g[v].pb(u);
	}

	dfs0(0, 0);
	bestV = 0;
	bestAns = sz(curr);
	dfs1(0, 0);

	cout << bestV + 1 << "\n";

}