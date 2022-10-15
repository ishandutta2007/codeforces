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
const double eps = 1e-12;

vector<int> ans;
vector<vector<int> > g, inv;

int dfs(int pos, int pr) {
	int res = 0;
	for (int i = 0; i < g[pos].size(); ++i) {
		int to = g[pos][i];
		if (to == pr)
			continue;
		ans[to] = ans[pos] + 1;
		res += dfs(to, pos);
	}
	for (int i = 0; i < inv[pos].size(); ++i) {
		int to = inv[pos][i];
		if (to == pr)
			continue;
		ans[to] = ans[pos] - 1;
		res += dfs(to, pos) + 1;
	}
	return res;

}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	ans.assign(n, 0);
	g.resize(n);
	inv.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		g[a].push_back(b);
		inv[b].push_back(a);
	}
	ans[0] = dfs(0, -1);
	dfs(0, -1);
	int m = n;
	for (int i = 0; i < n; ++i) {
		m = min(m, ans[i]);
	}
	cout << m << endl;
	for (int i = 0; i < n; ++i)
		if (ans[i] == m)
			cout << i + 1 << " ";
	cout << endl;
	return 0;
}