#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 200005;
const int MAXT = 530000;
int n, k;

struct seg{
	int tree[MAXT], lim;
	void init(int n){
		memset(tree, 0x3f, sizeof(tree));
		for(lim = 1; lim <= n; lim <<= 1);
	}
	void add(int x, int v){
		x += lim;
		tree[x] = v;
		while(x > 1){
			x >>= 1;
			tree[x] = min(tree[2*x], tree[2*x+1]);
		}
	}
	int query(int l, int r){
		l += lim; r += lim;
		int ret = 1e9;
		while(l < r){
			if(l % 2 == 1) ret = min(ret, tree[l++]);
			if(r % 2 == 0) ret = min(ret, tree[r--]);
			l >>= 1;
			r >>= 1;
		}
		if(l == r) ret = min(ret, tree[l]);
		return ret;
	}
}seg[32];

int a[MAXN][5];

int main(){
	scanf("%d %d",&n,&k);
	for(int i=0; i<(1<<k); i++) seg[i].init(n);
	for(int i=0; i<n; i++){
		for(int j=0; j<k; j++) scanf("%d",&a[i][j]);
		for(int j=0; j<(1<<k); j++){
			int ret = 0;
			for(int l=0; l<k; l++){
				if((j >> l) & 1) ret += a[i][l];
				else ret -= a[i][l];
			}
			seg[j].add(i, ret);
		}
	}
	int q; scanf("%d",&q);
	while(q--){
		int t; scanf("%d",&t);
		if(t == 2){
			int l, r, ret[32];
			scanf("%d %d",&l,&r);  l--, r--;
			for(int i=0; i<(1<<k); i++){
				ret[i] = seg[i].query(l, r);
			}
			int dap = 0;
			for(int i=0; i<(1<<k); i++){
				dap = max(dap, abs(ret[i] + ret[i ^ ((1<<k) - 1)]));
			}
			printf("%d\n", dap);
		}
		else{
			int i; scanf("%d",&i); i--;
			for(int j=0; j<k; j++) scanf("%d",&a[i][j]);
			for(int j=0; j<(1<<k); j++){
				int ret = 0;
				for(int l=0; l<k; l++){
					if((j >> l) & 1) ret += a[i][l];
					else ret -= a[i][l];
				}
				seg[j].add(i, ret);
			}
		}
	}
}