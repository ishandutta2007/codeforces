#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

vector<vector<int> > g;
vector<int> color;
vector<int> parent;
int k = 0;
int n;
int root;

void dfs(int v, int p)
{
	int ptr = 1;
	parent[v] = p;
	for (int to : g[v]) {
		if (color[to] == 0) {
			while (ptr == color[v] || ptr == color[p]) {
				++ptr;
			}
			color[to] = ptr++;
			dfs(to, v);
		}
	}
}

int main()
{

	//ifstream cin("strictly-off.in");
	//ofstream cout("strictly-off.out");
	//freopen("input.txt", "r", stdin);
	//freopen("threed.out", "w", stdout);
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	g.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		g[v].pb(u);
	}

	for (int i = 0; i < n; ++i) {
		if (sz(g[i]) + 1 > k) {
			k = sz(g[i]) + 1;
			root = i;
		}
	}

	color.resize(n);
	parent.resize(n);
	color[root] = 1;

	dfs(root, root);

	cout << k << "\n";
	for (int i = 0; i < n; ++i) {
		cout << color[i] << " ";
	}
	cout << "\n";

}