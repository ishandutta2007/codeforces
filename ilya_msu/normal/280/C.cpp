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

 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000;
//const int N = 100 * 1000 + 1;
vector<vector<int> > g;
vector<int> d;

void dfs(int pos, int p) {
	if (p != -1)
		d[pos] = d[p] + 1;
	for (int i = 0; i < g[pos].size(); ++i) {
		int to = g[pos][i];
		if (to != p)
			dfs(to, pos);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a, b;
	cin >> n;
	g.resize(n);
	d.assign(n, 0);
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b;
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	d[0] = 1;
	dfs(0, -1);
	double res = 0;
	for (int i = 0; i < n; ++i) {
		res += 1.0 / d[i];
	}
	printf("%0.10f\n", res);

	return 0;
}