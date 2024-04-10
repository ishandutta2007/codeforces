#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:64000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>

using std::pair;
using std::stringstream;
using std::next_permutation;
using std::sqrt;
using std::priority_queue;
using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;
using std::set;
using std::swap;
using std::random_shuffle;
using std::queue;
using std::sin;
using std::cos;
using std::make_pair;
using std::cos;
using std::cerr;
using std::map;

typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  

vector<vector<int> > g;
vector<bool> used;

int dfs(int pos, int pr) {
	used[pos] = true;
	int res = 1;
	for(int i = 0; i < g[pos].size(); ++i) {
		int to = g[pos][i];
		if (to == pr)
			continue;
		if (!used[to])
			res += dfs(to, pos);
	}
	return res;
}


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<bool> data(m * n);
	vector<pii> vertex;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			data[m * i + j] = (s[j] == '#');
			if (data[m * i + j])
				vertex.push_back(make_pair(i, j));
		}
	}
	g.resize(vertex.size());
	used.assign(g.size(), false);
	for (int i = 0; i < g.size(); ++i)
		for (int j = i + 1; j < g.size(); ++j)
			if (abs(vertex[i].first - vertex[j].first) + abs(vertex[i].second - vertex[j].second) == 1)
				g[i].push_back(j), g[j].push_back(i);
	if (dfs(0, -1) != g.size()) {
		cout << 0 << endl;
		return 0;
	}
	if (g.size() <= 2) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < g.size(); ++i) {
		used.assign(g.size(), false);
		used[i] = true;
		int x;
		if (i) {
			x = dfs(0, -1);
		}
		else {
			x = dfs(1, -1);
		}
		if (x + 1 != g.size()) {
			cout << 1 << endl;
			return 0;
		}
	}
	for (int i = 0; i < g.size(); ++i)
		for (int j = i + 1; j < g.size(); ++j) {
			used.assign(g.size(), false);
			used[i] = used[j] = true;
			int x;
			if (i) {
				x = dfs(0, -1);
			}
			else {
				if (j > 1)
					x = dfs(1, -1);
				else
					x = dfs(2, -1);
			}
			if (x + 2 != g.size()) {
				cout << 2 << endl;
				return 0;
			}
		}
	cout << -1 << endl;
	return 0;
}