#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(linker, "/STACK:128000000")
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
#include<unordered_map>

 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000;
//const int N = 100 * 1000 + 1;

vector<vector<int> > g;
vector<ll> v;
pll dfs(int pos, int p) {
	pll res(0, 0);
	for (int i = 0; i < g[pos].size(); ++i) {
		int to = g[pos][i];
		if (to == p)
			continue;
		pll cur = dfs(to, pos);
		cur.first += max((ll)0, v[to] - v[pos]);
		cur.second += max((ll)0, v[pos] - v[to]);
		res.first = max(res.first, cur.first);
		res.second = max(res.second, cur.second);
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a, b;
	cin >> n;
	g.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b;
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	v.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	pll res = dfs(0, -1);
	ll x = abs(v[0] + res.first - res.second) + res.first + res.second;
	cout << x << endl;
	return 0;
}