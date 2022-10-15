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
vector<int> d1, d2;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	d1.assign(n, 100);
	d2.assign(n, 100);
	d1[0] = 0;
	d2[n - 1] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < g[j].size(); ++k) {
				int to = g[j][k];
				if (d1[to] > d1[j] + 1)
					d1[to] = d1[j] + 1;
				if (d2[to] > d2[j] + 1)
					d2[to] = d2[j] + 1;
			}
		}
	}
	int d = d1[n - 1];
	vector<vector<int> > g1(n), g2(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < g[i].size(); ++j) {
			int to = g[i][j];
			if (d1[i] + d2[to] == d - 1)
				g1[i].push_back(to);
			if (d2[i] + d1[to] == d - 1)
				g2[i].push_back(to);
		}
	}
	vector<ll> a1(n, 0), a2(n, 0);
	a1[0] = a2[n - 1] = 1;
	queue<int> t1;
	t1.push(0);
	vector<bool> u1(n, false);
	u1[0] = true;
	while(!t1.empty()) {
		int v = t1.front();
		t1.pop();
		for (int i = 0; i < g1[v].size(); ++i) {
			a1[g1[v][i]] += a1[v];
			if (!u1[g1[v][i]]) {
				t1.push(g1[v][i]);
				u1[g1[v][i]] = true;
			}
		}
	}
	queue<int> t2;
	t2.push(n - 1);
	vector<bool> u2(n, false);
	u2[n - 1] = true;
	while(!t2.empty()) {
		int v = t2.front();
		t2.pop();
		for (int i = 0; i < g2[v].size(); ++i) {
			a2[g2[v][i]] += a2[v];
			if (!u2[g2[v][i]]) {
				t2.push(g2[v][i]);
				u2[g2[v][i]] = true;
			}
		}
	}
	double ans = 1.0;
	for (int i = 1; i < n - 1; ++i) {
		ans = max(ans, 2.0 * a1[i] * (double)(a2[i]) / a2[0]);
	}
	printf("%0.10f\n", ans);

	return 0;
}