#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:128000000")
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

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)
 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000;
const ll LLINF = (ll)8 * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const int N = 20 * 1000 + 10;
const ll MOD = 1000 * 1000 * 1000 + 7;

vector<int> d;
vector<int> m;
vector<int> p;
vector<vector<int> > g;

void dfs(int pos, int pr = -1) {
	p[pos] = pr;
	for (int i = 0; i < g[pos].size(); ++i) {
		int to = g[pos][i];
		if (to == pr)
			continue;
		dfs(to, pos);
	}
	if (pr == -1) {
		m[pos] = d[pos];
		return;
	}
	if (p[pr] == -1) {
		m[pos] = d[pos];
		return;
	}
	int pp = p[pr];
	m[pos] = d[pos] ^ d[pp];
}

int main() {
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	g.resize(n);
	int a, b;
	for (int i = 0; i + 1 < n; ++i) {
		cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int> init(n), goal(n);
	d.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> init[i];
	for (int i = 0; i < n; ++i)
		cin >> goal[i];
	for (int i = 0; i < n; ++i)
		d[i] = init[i] ^ goal[i];
	m.assign(n, 0);
	p.resize(n);
	dfs(0);
	vector<int> res;
	for (int i = 0; i < n; ++i) {
		if (m[i])
			res.push_back(i + 1);
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << "\n";
	
	return 0;
}