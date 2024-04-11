#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int MAXN = 200005;
const int mod = 1e9 + 7;

vector<int> gph[MAXN];
int sz[MAXN][2], par[MAXN], dep[MAXN];

void dfs(int x, int p){
	sz[x][dep[x]]++;
	for(auto &i : gph[x]){
		if(i != p){
			par[i] = x;
			dep[i] = 1 - dep[x];
			dfs(i, x);
			sz[x][0] += sz[i][0];
			sz[x][1] += sz[i][1];
		}
	}
}

int n, a[MAXN];
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	for(int i=1; i<n; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	dfs(1, 0);
	lint ans = 0;
	for(int i=1; i<=n; i++){
		lint sum = n;
		for(auto &j : gph[i]){
			if(j == par[i]) continue;
			sum += 1ll * sz[j][dep[i]] * (n - sz[j][0] - sz[j][1]);
			sum -= 1ll * sz[j][dep[i]^1] * (n - sz[j][0] - sz[j][1]);
			sum %= mod;
			sum += mod;
		}
		sum += 1ll * (sz[1][dep[i]] - sz[i][dep[i]]) * (sz[i][0] + sz[i][1]);
		sum -= 1ll * (sz[1][dep[i]^1] - sz[i][dep[i]^1]) * (sz[i][0] + sz[i][1]);
		sum %= mod;
		sum += mod;
		ans += sum * (a[i] + mod) % mod;
		ans %= mod;
	}
	cout << ans << endl;
}