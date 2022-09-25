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
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 3 * (1 << 17);
const int inf = 1000000007;
const int mod = 1000000007;

int n, m;
int balance[maxn], a[maxn];
vector<int> e[maxn];
set<pair<int, int> > st;

void f(int v) {
	st.erase(make_pair(balance[v], v));
	balance[v] = 0;
	for (int i = 0; i < e[v].size(); i++)
		balance[v] -= a[v] == a[e[v][i]];
	st.insert(make_pair(balance[v], v));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		balance[u]--;
		balance[v]--;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	for (int i = 1; i <= n; i++)
		st.insert(make_pair(balance[i], i));

	while (1) {
		int v = st.begin()->second;
		if (balance[v] > -2) break;
		a[v] ^= 1;
		f(v);
		for (int i = 0; i < e[v].size(); i++)
			f(e[v][i]);
	}

	for (int i = 1; i <= n; i++)
		printf("%d", a[i]);

	return 0;
}