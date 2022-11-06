#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <memory.h>
#include <string.h>
#include <complex>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x).size()

vector<int> v[150150];
bool vis[150150];


void dfs(int s, vector<int>& tmp) {
	vis[s] = true;
	tmp.pb(s);
	for(int i = 0; i < sz(v[s]); i++) {
		int nxt = v[s][i];
		if (!vis[nxt]) {
			dfs(nxt, tmp);
		}
	}
}


int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}

	for(int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vector<int> tmp;
			dfs(i, tmp);
			ll ecnt = 0;
			for(int j = 0; j < sz(tmp); j++) {
				ecnt += sz(v[tmp[j]]);
			}
			ll x = sz(tmp);
			ll need = x * (x - 1);
			if (ecnt != need) {
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES");



	return 0;
}