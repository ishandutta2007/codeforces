#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<lint, lint> pi;

int n, m;
bitset<1001> prime;

struct tree{
	bitset<1001> tree[270000];
	int lazy[270000];
	void init(int s, int e, int p){
		tree[p] = 1;
		if(s == e) return;
		int m = (s+e)/2;
		init(s, m, 2*p);
		init(m+1, e, 2*p+1);
	}
	void apply(int x, int v){
		lazy[x] = (lazy[x] + v) % m;
		tree[x] = (tree[x] << v) | (tree[x] >> (m - v));
	}
	void add(int s, int e, int ps, int pe, int p, int v){
		if(e < ps || pe < s) return;
		if(s <= ps && pe <= e){
			apply(p, v);
			return;
		}
		if(lazy[p]){
			apply(2*p, lazy[p]);
			apply(2*p+1, lazy[p]);
			lazy[p] = 0;
		}
		int pm = (ps + pe) / 2;
		add(s, e, ps, pm, 2*p, v);
		add(s, e, pm+1, pe, 2*p+1, v);
		tree[p] = tree[2*p] | tree[2*p+1];
	}
	bitset<1001> query(int s, int e, int ps, int pe, int p){
		if(e < ps || pe < s) return bitset<1001>();
		if(s <= ps && pe <= e){
			return tree[p];
		}
		if(lazy[p]){
			apply(2*p, lazy[p]);
			apply(2*p+1, lazy[p]);
			lazy[p] = 0;
		}
		int pm = (ps + pe) / 2;
		return query(s, e, ps, pm, 2*p) | query(s, e, pm+1, pe, 2*p+1);
	}
}seg;

vector<int> gph[100005];
int dfn[100005], sz[100005], piv, rev[100005];
int a[100005];

void dfs(int x, int p){
	dfn[x] = ++piv;
	rev[dfn[x]] = x;
	sz[x] = 1;
	for(auto &i : gph[x]){
		if(i == p) continue;
		dfs(i, x);
		sz[x] += sz[i];
	}
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		a[i] %= m;
	}
	for(int i=1; i<n; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	for(int i=2; i<m; i++){
		prime[i] = 1;
		for(int j=2; j<i; j++){
			if(i % j == 0){
				prime[i] = 0;
			}
		}
	}
	dfs(1, 0);
	seg.init(1, n, 1);
	for(int i=1; i<=n; i++){
		seg.add(dfn[i], dfn[i], 1, n, 1, a[i]);
	}
	int q; scanf("%d",&q);
	for(int i=0; i<q; i++){
		int t; scanf("%d",&t);
		if(t == 1){
			int v, x; scanf("%d %d",&v, &x);
			x %= m;
			seg.add(dfn[v], dfn[v] + sz[v] - 1, 1, n, 1, x);
		}
		else{
			int v;
			scanf("%d",&v);
			auto t = seg.query(dfn[v], dfn[v] + sz[v] - 1, 1, n, 1);
			t &= prime;
			printf("%d\n",t.count());
		}
	}
}