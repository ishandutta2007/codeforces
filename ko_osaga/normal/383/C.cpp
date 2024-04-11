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
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, m, a[200005], piv;
int dfn[200005], size[200005], dep[200005];
vector<int> gph[200005];

struct seg{
	int tree[200005];
	void add(int x, int v){
		while(x <= n+1){
			tree[x] += v;
			x += x & -x;
		}
	}
	int query(int x){
		int ret = 0;
		while(x){
			ret += tree[x];
			x -= x & -x;
		}
		return ret;
	}
}seg0, seg1;

void dfs(int x, int p){
	dfn[x] = ++piv;
	size[x] = 1;
	for(auto &i : gph[x]){
		if(i == p) continue;
		dep[i] = dep[x] + 1;
		dfs(i, x);
		size[x] += size[i];
	}
}

int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);		
	}
	for(int i=0; i<n-1; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	dfs(1, 0);
	for(int i=0; i<m; i++){
		int t;
		scanf("%d",&t);
		if(t == 1){
			int x, y;
			scanf("%d %d",&x, &y);
			int rs = dfn[x], re = dfn[x] + size[x] - 1;
			if(dep[x] % 2 == 1) y = -y;
			seg0.add(rs, y);
			seg0.add(re+1, -y);
			seg1.add(rs, -y);
			seg1.add(re+1, y);
		}
		else{
			int x;
			scanf("%d",&x);
			if(dep[x] % 2 == 1){
				printf("%d\n",seg1.query(dfn[x]) + a[x]);
			}
			else{
				printf("%d\n",seg0.query(dfn[x]) + a[x]);
			}
		}
	}
}