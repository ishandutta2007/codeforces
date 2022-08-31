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

struct seg{
	int tree[270000], lazy[270000];
	void apply(int x, int ps, int pe){
		tree[x] = pe - ps + 1 - tree[x];
		lazy[x] ^= 1;
	}
	void flip(int s, int e, int ps, int pe, int p){
		if(e < ps || pe < s) return;
		if(s <= ps && pe <= e){
			apply(p, ps, pe);
			return;
		}
		int pm = (ps + pe) / 2;
		if(lazy[p]){
			apply(2*p, ps, pm);
			apply(2*p+1, pm+1, pe);
			lazy[p] = 0;
		}
		flip(s, e, ps, pm, 2*p);
		flip(s, e, pm+1, pe, 2*p+1);
		tree[p] = tree[2*p] + tree[2*p+1];
	}
	int query(int s, int e, int ps, int pe, int p){
		if(e < ps || pe < s) return 0;
		if(s <= ps && pe <= e) return tree[p];
		int pm = (ps + pe) / 2;
		if(lazy[p]){
			apply(2*p, ps, pm);
			apply(2*p+1, pm+1, pe);
			lazy[p] = 0;
		}
		return query(s, e, ps, pm, 2*p) + query(s, e, pm+1, pe, 2*p+1);
	}
}seg[20];

int n;

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int t;
		scanf("%d",&t);
		for(int j=0; j<20; j++){
			if((t >> j) & 1){
				seg[j].flip(i, i, 1, n, 1);
			}
		}
	}
	int q; scanf("%d",&q);
	while(q--){
		int t; scanf("%d",&t);
		if(t == 1){
			int s, e;
			scanf("%d %d",&s,&e);
			lint ret = 0;
			for(int j=0; j<20; j++){
				ret += (1ll * seg[j].query(s, e, 1, n, 1)) << j;
			}
			printf("%lld\n",ret);
		}
		else{
			int s, e, x;
			scanf("%d %d %d",&s,&e,&x);
			for(int j=0; j<20; j++){
				if((x >> j) & 1){
					seg[j].flip(s, e, 1, n, 1);
				}
			}
		}
	}
}