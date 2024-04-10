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
#include<hash_map>

 
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

vector<vector<int> > g;
vector<int> used;

void dfs(int pos) {
	used[pos] = 1;
	for (int i = 0; i < g[pos].size(); ++i) {
		int to = g[pos][i];
		if (used[to])
			continue;
		dfs(to);
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
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	used.assign(n, 0);
	int st = n;
	for (int i = 0; i < n; ++i) {
		if (used[i])
			continue;
		dfs(i);
		--st;
	}
	ll res = 1;
	for (int i = 0; i < st; ++i)
		res *= 2;
	cout << res << endl;
	
	return 0;
}