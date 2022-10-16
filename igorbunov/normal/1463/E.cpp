#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define endl "\n"

vector<int> g1[300000];
vector<int> g[300000];
vector<int> used(300000);

void dfs_check(int v) {
	used[v] = 1;
	for (auto u: g1[v]) {
		if (used[u] == 1) {
			cout << 0;
			exit(0);
		}
		dfs_check(u);
	}
	used[v] = 2;
}

vector<int> path;

void dfs_path(int v) {
	path.push_back(v);
	for (auto u: g1[v]) {
		dfs_path(u);
	}
}

vector<int> used1(300000);
vector<int> top_sort; 
void dfs_top_sort(int v) {
	used1[v] = 1;
	for (auto u: g[v]) {
		if (used1[u] == 1) {
			cout << 0;
			exit(0);
		}
		if (used1[u] == 2) {
			continue;
		}
		dfs_top_sort(u);
	}
	used1[v] = 2;
	top_sort.push_back(v);
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> edges;
	int ind;
	for (int i = 0; i < n; i++) {
		int pr;
		cin >> pr;
		pr--;
		if (pr == -1) {
			ind = i;
			continue;
		}
		edges.push_back(make_pair(pr, i));
	}
	vector<bool> good(n, true);
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		good[y] = false;
		g1[x].push_back(y);
	}
	for (int i = 0; i < n; i++) {
		if (used[i] == 0) { 
			dfs_check(i);
		}
	}
	vector<int> colour(n);
	vector<int> pos(n);
	vector<vector<int>> all;
	int now_c = 0;
	for (int i = 0; i < n; i++) {
		if (good[i]) {
			path.clear();
			dfs_path(i);
			int now_pos = 0;
			for (auto v: path) {
				colour[v] = now_c;
				pos[v] = now_pos;
				now_pos++;
			}
			//cout << endl;
			all.push_back(path);
			now_c++;
		}
	}

	for (int i = 0; i < edges.size(); i++) {
		auto p = edges[i];
		int a = p.first;
		int b = p.second;
		if (colour[a] == colour[b]) {
			if (pos[a] > pos[b]) {
				/*cout << "BAN\n";
				cout << a << " " << b << endl;
				cout << pos[a] << " " << pos[b] << endl;
				cout << 0;*/
				cout << 0;
				exit(0);
			}
		} else {
			//cout << colour[a] << " " << colour[b] << endl;
			g[colour[a]].push_back(colour[b]);
		}
	}
	dfs_top_sort(colour[ind]);
	reverse(top_sort.begin(), top_sort.end());
	for (auto v: top_sort) {
		//cout << v << "   ";
		for (auto u: all[v]) {
			cout << u + 1 << " ";
		}
		//cout << endl;
	}
}