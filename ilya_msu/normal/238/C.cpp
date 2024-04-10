#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(linker, "/STACK:64000000")
//#define _USE_MATH_DEFINES
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
#include<ctime>

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
using std::clock;
using std::nth_element;


typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-13;
const int INF = 1000 * 1000;

int mod = 1000 * 1000 * 1000 + 9;

vector<vector<int> > g;
vector<vector<int> > inv;
//vector<vector<int> > d;
vector<int> c;
int n;
int k;
int d = 0;

pii dfs(int pos, int pr) {
	pii res(0, 0);
	int dif = 0;
	for (int i = 0; i < g[pos].size(); ++i) {
		int to = g[pos][i];
		if (to == pr)
			continue;
		pii x = dfs(to, pos);
		res.first += x.first;
		dif = max(dif, x.first - x.second - 1);
	}
	for (int i = 0; i < inv[pos].size(); ++i) {
		int to = inv[pos][i];
		if (to == pr)
			continue;
		pii x = dfs(to, pos);
		res.first += x.first + 1;
		dif = max(dif, x.first - x.second + 1);
	}
	d = max(d, dif);
	res.second = res.first - dif;
	return res;
}
//
//void dfs(int pos, int pr, int c) {
//	if (pr != -1) {
//		d[k][pos] = d[k][pr] + c;
//	}
//	for (int i = 0; i < g[pos].size(); ++i) {
//		int to = g[pos][i];
//		if (to == pr)
//			continue;
//		dfs(to, pos, 0);
//	}
//	for (int i = 0; i < inv[pos].size(); ++i) {
//		int to = inv[pos][i];
//		if (to == pr)
//			continue;
//		dfs(to, pos, 1);
//	}
//}


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "r", stdin);
	cin >> n;
	g.resize(n);
	inv.resize(n);
	//d.assign(n, -1);
	for (int i = 0; i + 1 < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		g[a].push_back(b);
		inv[b].push_back(a);
		//g[b].push_back(a);

	}
	vector<int> st;
	for (int i = 0; i < n; ++i) {
		if (inv[i].empty())
			st.push_back(i);
	}
	int res = n;
	for (int i = 0; i < st.size(); ++i) {
		int x = st[i];
		d = 0;
		pii y = dfs(x, -1);
		res = min(res, y.first - d);
	}
	cout << res << endl;
	return 0;
}