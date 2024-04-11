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
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int n;
int dep[300005], dfn[300005], size[300005], piv;
vector<int> graph[300005];

struct bit{
	int tree[300005];
	void add(int x, int v){
		while(x <= n){
			tree[x] = (tree[x] + v) % mod;
			x += x & -x;
		}
	}
	int query(int x){
		int ret = 0;
		while(x){
			ret = (ret + tree[x]) % mod;
			x -= x & -x;
		}
		return ret;
	}
}bit1, bit2;

void dfs(int x){
	size[x] = 1;
	dfn[x] = ++piv;
	for(auto &i : graph[x]){
		dep[i] = dep[x] + 1;
		dfs(i);
		size[x] += size[i];
	}
}

int main(){
	scanf("%d",&n);
	for(int i=2; i<=n; i++){
		int t;
		scanf("%d",&t);
		graph[t].push_back(i);
	}
	dfs(1);
	int q;
	scanf("%d",&q);
	while(q--){
		int t;
		scanf("%d",&t);
		if(t == 1){
			int p, a, b;
			scanf("%d %d %d",&p,&a,&b);
			bit1.add(dfn[p], (1ll * dep[p] * b + a) % mod);
			bit1.add(dfn[p] + size[p], mod - (1ll * dep[p] * b + a) % mod);
			bit2.add(dfn[p], mod - b);
			bit2.add(dfn[p] + size[p], b);
		}
		else{
			int x;
			scanf("%d",&x);
			printf("%lld\n",(bit1.query(dfn[x]) + 1ll * dep[x] * bit2.query(dfn[x])) % mod);
		}
	}
}