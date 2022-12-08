#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>
#include <math.h>
#include <random>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 998244353;

vector<vector<int>> edge;
set<pair<int, int>> bridge;
vector<int> cols;
vector<int> up;
vector<int> tin;
vector<pair<int, int>> edge2;
int col = 1;
int tim = 1;

void dfs1(int v, int p) {
	tin[v] = up[v] = tim++;
	for (int u : edge[v]) {
		if (u == p) continue;
		if (!tin[u]) {
			dfs1(u, v);
			up[v] = min(up[v], up[u]);
		}
		up[v] = min(up[v], tin[u]);
		if (tin[v] < up[u]) {
			bridge.insert({ v, u });
			bridge.insert({ u, v });
			edge2.push_back({ v, u });
		}
	}
}


void dfs2(int v) {
	cols[v] = col;
	for (int u : edge[v]) {
		if (cols[u] || bridge.find({ v, u }) != bridge.end()) continue;
		dfs2(u);
	}
}

vector<vector<int>> ed;


pair<int, int> dfs3(int v, int p) {
	pair<int, int> an = { -1, v };
	for (int u : ed[v]) {
		if (u != p) {
			pair<int, int> t = dfs3(u, v);
			if (t.first > an.first) {
				an = t;
			}
		}
	}
	an.first++;
	return an;
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	edge.resize(n);
	tin.resize(n);
	up.resize(n);
	cols.resize(n);
	int t1, t2;
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2; t1--; t2--;
		edge[t1].push_back(t2);
		edge[t2].push_back(t1);
	}
	dfs1(0, -1);
	/*for (int i = 0; i < n; i++) {
		cout << i + 1 << " " << tin[i] << " " << up[i] << endl;
	}*/
	//cout << " ------ \n";
	for (int i = 0; i < n; i++) {
		if (!cols[i]) {
			dfs2(i);
			col++;
		}
	}
	/*for (int i = 0; i < n; i++) {
		cout << i + 1 << " " << cols[i] << endl;
	}*/
	ed.resize(col);
	for (auto i : edge2) {
		ed[cols[i.first]].push_back(cols[i.second]);
		ed[cols[i.second]].push_back(cols[i.first]);
	}
	cout << dfs3(dfs3(1, -1).second, -1).first << endl;
	//system("pause");
	return 0;
}