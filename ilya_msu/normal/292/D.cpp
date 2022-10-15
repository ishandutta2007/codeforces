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
const int INF = 1000 * 1000 * 1000;
const int N = 1000 * 1000 * 10 + 1;
int l, r;
vector<int> used;
vector<vector<pii> > g;

void dfs(int pos) {
	used[pos] = true;
	for (int i = 0; i < g[pos].size(); ++i) {
		pii p = g[pos][i];
		if ((p.second < l) || (p.second > r)) {
			if (!used[p.first])
				dfs(p.first);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a, b;
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		--a;
		--b;
		g[a].push_back(make_pair(b, i));
		g[b].push_back(make_pair(a, i));		
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> l >> r;
		--l;
		--r;
		int ans = 0;
		used.assign(n, false);
		for (int j = 0; j < n; ++j)
			if (!used[j]) {
				dfs(j);
				++ans;
			}
		printf("%d\n", ans);
	}
	return 0;
}