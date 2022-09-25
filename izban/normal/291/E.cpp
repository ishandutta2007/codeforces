#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <assert.h>
#include <memory.h>

using namespace std;

#define ll long long


#pragma comment(linker, "/STACK:64000000")
const int maxn = 1 << 17, maxm = 2.5 * maxn;
const int inf = 1000000007;
const int mod = 1000000007;

int n, ans;
int p[maxn], go[maxm][26];
string s[maxn], t;
vector<int> e[maxn], pr;

void dfs(int v, int k) {
	for (int i = 0; i < e[v].size(); i++) {
		int to = e[v][i];
		int x = k;
		for (int j = 0; j < s[to].size(); j++) {
			x = go[x][s[to][j] - 'a'];
			ans += x == t.size();
		}
		dfs(to, x);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n;
	for (int i = 2; i <= n; i++)
		cin >> p[i] >> s[i], e[p[i]].push_back(i);
	cin >> t;
	pr.resize(t.size());
	
	go[0][t[0] - 'a'] = 1;
	for (int i = 1; i < t.size(); i++) {
		pr[i] = pr[i - 1];
		while (pr[i] && t[i] != t[pr[i]]) pr[i] = pr[pr[i] - 1];
		pr[i] += t[i] == t[pr[i]];
		for (int j = 0; j < 26; j++) go[i][j] = go[pr[i - 1]][j];
		go[i][t[i] - 'a'] = i + 1;
	}
	for (int i = 0; i < 26; i++) go[t.size()][i] = go[pr[t.size() - 1]][i];

	dfs(1, 0);
	cout << ans << endl;

	return 0;
}