#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>
#include<cmath>

using namespace std;
//#define LOCAL

const int INF = 1e9;
const long long up = 398671;
const long long mod = 1e9 + 7;
vector< vector<int> > g;
vector<int> col;
vector< vector<int> > same, other;
vector<int> p;

void dfs(int v) {
	for (int i : same[v]) {
		if (col[i] == INF) {
			col[i] = col[v];
		}
	}
	for (int i : other[v]) {
		if (col[i] == INF) {
			p[i] = v;
			if (p[v] == -1 || col[p[v]] < col[v]) {
				if (p[v] == -1)
					p[v] = i;
				col[i] = col[v] + 1;
			}
			else
				col[i] = col[v] - 1;
			dfs(i);
		}
	}
}

bool comp(pair<int, vector<int> > a, pair<int, vector<int> > b) {
	return(a.second.size() < b.second.size() || (a.second.size() == b.second.size() && a.second < b.second));
}

multiset<int> al;

bool check() {
	for (int i = 0; i < g.size(); i++) {
		al.erase(al.find(col[i]));
		for (int j : g[i]) {
			if (abs(col[j] - col[i]) > 1)
				return 0;
			al.erase(al.find(col[j]));
		}
		if (!al.empty()) {
			auto j = al.upper_bound(col[i]);
			auto q = al.lower_bound(col[i]);
			if ((j != al.end()  && abs((*j) - col[i]) <= 1) || (q != al.end() && abs((*q) - col[i]) <= 1))
				return 0;
		}
		al.insert(col[i]);
		for (int j : g[i]) {
			al.insert(col[j]);
		}
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	g.resize(n);
	col.resize(n, INF);
	vector<long long> arrp(5e5);
	arrp[0] = 1;
	for (int i = 1; i < 5e5; i++) {
		arrp[i] = (arrp[i - 1] * up) % mod;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	same.resize(n);
	other.resize(n);
	p.resize(n, -1);
	col[0] = 1e6;
	vector< vector<long long> > hash(n);
	vector< map<int, int> > pos(n);
	for (int i = 0; i < n; i++) {
		sort(g[i].begin(), g[i].end());
		hash[i].resize(g[i].size() + 1);
		for (int j = 0; j < g[i].size(); j++) {
			hash[i][j + 1] = (hash[i][j] * up + g[i][j] + 1) % mod;
			pos[i][g[i][j]] = j;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j : g[i]) {
			int a1 = ((hash[i][pos[i][j]] * arrp[g[i].size() - pos[i][j] - 1] + (hash[i][g[i].size()] - hash[i][pos[i][j] + 1] * arrp[g[i].size() - pos[i][j] - 1]))% mod + mod) % mod;
			int a2 = ((hash[j][pos[j][i]] * arrp[g[j].size() - pos[j][i] - 1] + (hash[j][g[j].size()] - hash[j][pos[j][i] + 1] * arrp[g[j].size() - pos[j][i] - 1])) % mod + mod) % mod;
			if (a1 == a2)
				same[i].push_back(j);
			else
				other[i].push_back(j);
		}
	}
	dfs(0);
	for (int i = 0; i < n; i++) {
		al.insert(col[i]);
	}
	if (check()) {
		cout << "YES\n";
		for (int i = 0; i < n; i++)
			cout << col[i] << ' ';
	}
	else {
		cout << "NO";
	}
	
	return 0;
}