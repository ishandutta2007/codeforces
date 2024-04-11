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

int n, a[100005], b[100005];

struct seg{
	pi tree[270000];
	int lim, ts;
	void init(int n){
		for(lim = 1; lim <= n; lim <<= 1);
		fill(tree, tree+270000, pi(-1, 1e9));
	}
	void set(int s, int e, int x){
		s += lim;
		e += lim;
		ts++;
		pi node = pi(ts, x);
		while(s < e){
			if(s%2 == 1){
				tree[s] = max(tree[s], node);
				s++;
			}
			if(e%2 == 0){
				tree[e] = max(tree[e], node);
				e--;
			}
			s >>= 1;
			e >>= 1;
		}
		if(s == e) tree[s] = max(tree[s], node);
	}
	int query(int x){
		x += lim;
		pi ret(-1, 1e9);
		while(x){
			ret = max(ret, tree[x]);
			x >>= 1;
		}
		return ret.second;
	}
}seg;

int main(){
	int q;
	cin >> n >> q;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	for(int i=1; i<=n; i++){
		scanf("%d",&b[i]);
	}
	seg.init(n);
	while(q--){
		int t;
		scanf("%d",&t);
		if(t == 1){
			int x, y, k;
			scanf("%d %d %d",&x,&y,&k);
			seg.set(y, y+k-1, x-y);
		}
		else{
			int u;
			scanf("%d",&u);
			int t = seg.query(u);
			if(t > 1e8){
				printf("%d\n",b[u]);
			}
			else{
				printf("%d\n",a[u+t]);
			}
		}
	}
}