#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
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
#include<ctime>
#include<cstdio>
#include<cassert>



 
using namespace std; 
 
typedef long long ll; 
typedef long double ld;
typedef unsigned int uint; 
typedef unsigned long long ull; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const int N = 1001;
//const int M = 10000000;

vector<vector<int> > g;
vector<int> x;
vector<int> used1;
vector<vector<int> > tree;
vector<int> sub;

int dfs1(int pos) {
	int res = x[pos];
	used1[pos] = 1;
	for (int i = 0; i < g[pos].size(); ++i) {
		int to = g[pos][i];
		if (used1[to])
			continue;
		tree[pos].push_back(to);
		//tree[].push_back(to);

		res += dfs1(to);
	}
	sub[pos] = res;
	return res;	
}

vector<int> path;

void dfs2(int pos, int pr = -1) {
	path.push_back(pos);
	for (int i = 0; i < tree[pos].size(); ++i) {
		int to = tree[pos][i];
		if (to == -1)
			continue;
		if (sub[to]) {
			dfs2(to);
			path.push_back(pos);
		}
	}
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("INPUT.TXT", "r", stdin);
	//freopen("OUTPUT.TXT", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	x.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> x[i];
	vector<int> s;
	used1.assign(n, 0);
	tree.resize(n);
	sub.assign(n, 0);
	for (int i = 0; i < n; ++i) {
		if (used1[i])
			continue;
		int y = dfs1(i);
		if (y != 0)
			s.push_back(i);
	}
	if (s.size() > 1) {
		cout << -1 << endl;
		return 0;
	}
	if (s.size() == 0) {
		cout << 0 << endl;
		return 0;
	}
	dfs2(s[0]);
	vector<int> res;
	for (int i = 0; i < path.size(); ++i) {
		x[path[i]] = 1 - x[path[i]];
		if (x[path[i]] == 0) {
			res.push_back(path[i]);
			continue;
		}
		if (i + 1 == path.size())
			continue;
		x[path[i]] = 0;
		x[path[i + 1]] = 1 - x[path[i + 1]];
		res.push_back(path[i]);
		res.push_back(path[i + 1]);
		res.push_back(path[i]);
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] + 1 << " ";
	cout << endl;

	return 0;
}