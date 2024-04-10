#include <vector>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;
const int MAX_n = 210, MAX_m = 20010;
int n, m;
vector<int> adj[MAX_n];
bool real[MAX_n][MAX_n], avai[MAX_n][MAX_n];
vector<pii> edg;

void trav(int v) {
	while (adj[v].size() && !avai[v][adj[v].back()] && !real[v][adj[v].back()]) {
		adj[v].pop_back();
	}
	if (adj[v].empty()) return;
	int u = adj[v].back();
	adj[v].pop_back();
	if (real[v][u]) edg.push_back(pii(v, u)),real[v][u]=real[u][v]=false;
	else avai[v][u] = avai[u][v] = false;
	trav(u);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	for (cin >> t; t > 0; --t) {
		cin >> n >> m;
		// re-ini
		for (int i = 0; i < n; ++i) {
			adj[i] = vector<int>();
		}
		edg = vector<pii>();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				real[i][j] = avai[i][j] = false;
			}
		}
		// main
		for (int i = 0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
			--x, --y;
			adj[x].push_back(y);
			adj[y].push_back(x);
			real[x][y] = real[y][x] = true;
		}
		int t = -1, ans = 0;
		for (int i = 0; i < n; ++i) {
			if (adj[i].size() % 2) {
				if (t == -1)
					t = i;
				else {
					adj[t].push_back(i);
					adj[i].push_back(t);
					avai[i][t] = avai[t][i] = true;
					t = -1;
				}
			} else {
				++ans;
			}
		}
		if (ans > n) {
			cout << "-1\n";
			return 0;
		} else {
			cout << ans << '\n';
		}
		for (int i = 0; i < n; ++i) {
			trav(i);
		}
		for (int i = 0; i < edg.size(); ++i) {
//			if (edg[i].first > n || edg[i].second > n) {
//				cout << "-1 -1\n";
//			} else {
				cout << edg[i].first + 1 << ' ' << edg[i].second + 1 << '\n';
//			}
		}
	}
	return 0;
}