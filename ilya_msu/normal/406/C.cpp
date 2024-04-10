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
typedef pair<long double, long double> pdd;

typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 10000000;
//const int N = 1000 * 1000 * 1000 + 10;
const int MOD = 1000 * 1000 * 1000 + 7;

struct tri {
	int a, b, c;
	tri(int aa, int bb, int cc) : a(aa), b(bb), c(cc) {}
	tri() {}
};

int n, m;
vector<vector<int> > g, g1, g2;
vector<int> num;
vector<int> used;
vector<tri> ans;
int number;

void dfs(int pos = 0, int pr = -1) {
	num[pos] = ++number;
	used[pos] = 1;
	//int x = 0;
	for (int i = 0; i < g[pos].size(); ++i) {
		int to = g[pos][i];
		if (to == pr)
			continue;
		if (used[to]) {
			if (num[to] < num[pos])
				g2[pos].push_back(to);
			continue;

		}
		g1[to].push_back(pos);
		dfs(to, pos);
		//x += dfs(g[pos][i]) + 1;
	}
	while(g2[pos].size() > 1) {
		ans.push_back(tri(g2[pos][g2[pos].size() - 1], pos, g2[pos][g2[pos].size() - 2]));
		g2[pos].pop_back();
		g2[pos].pop_back();
	}
	if (!g2[pos].empty()) {
		ans.push_back(tri(g2[pos][0], pos, g1[pos][0]));
		//g2[g2[pos][0]].push_back(pos);
		g2[pos].pop_back();
		g1[pos].pop_back();
	}
	for (int i = 0; i < g1[pos].size(); ++i) {
		g2[g1[pos][i]].push_back(pos);
	}

	//d[pos] = x;
	//return x;
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &m);
	g.resize(n);
	g1.resize(n);
	g2.resize(n);
	number = 0;
	num.assign(n, 0);
	used.assign(n, 0);
	for (int i = 0 ; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	if (m & 1) {
		printf("No solution\n");
		return 0;
	}
	dfs();
	for (int i = 0; i < ans.size(); ++i) 
		printf("%d %d %d\n", ans[i].a + 1, ans[i].b + 1, ans[i].c + 1);
	
    return 0;
}