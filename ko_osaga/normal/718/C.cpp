#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

struct mat{
	lint a[2][2];
	void init(){
		memset(a, 0, sizeof(a));
	}
	mat operator*(const mat &b)const{
		mat c;
		for(int i=0; i<2; i++){
			for(int j=0; j<2; j++){
				c.a[i][j] = 0;
				for(int k=0; k<2; k++){
					c.a[i][j] += a[i][k] * b.a[k][j];
				}
				c.a[i][j] %= mod;
			}
		}
		return c;
	}
	mat operator+(const mat &b)const{
		mat c;
		for(int i=0; i<2; i++){
			for(int j=0; j<2; j++){
				c.a[i][j] = (a[i][j] + b.a[i][j]) % mod;
			}
		}return c;
	}
};

mat ppow(int x){
	mat ret, piv;
	ret.init(), piv.init();
	ret.a[0][0] = ret.a[1][1] = 1;
	piv.a[0][0] = piv.a[0][1] = piv.a[1][0] = 1;
	while(x){
		if(x&1) ret = ret * piv;
		piv = piv * piv;
		x >>= 1;
	}
	return ret;
}

struct seg{
	mat tree[270005];
	mat lazy[270005];
	void init(int s, int e, int x, int *a){
		lazy[x].init();
		lazy[x].a[0][0] = lazy[x].a[1][1] = 1;
		if(s == e){
			tree[x] = ppow(a[s]-1);
			return;
		}
		int m = (s+e)/2;
		init(s, m, 2*x, a);
		init(m+1, e, 2*x+1, a);
		tree[x] = tree[2*x] + tree[2*x+1];
	}
	void lazydown(int p){
		tree[2*p] = tree[2*p] * lazy[p];
		tree[2*p+1] = tree[2*p+1] * lazy[p];
		lazy[2*p] = lazy[2*p] * lazy[p];
		lazy[2*p+1] = lazy[2*p+1] * lazy[p];
		lazy[p].init();
		lazy[p].a[0][0] = lazy[p].a[1][1] = 1;
	}
	void upd(int s, int e, int ps, int pe, int p, mat v){
		if(e < ps || pe < s) return;
		if(s <= ps && pe <= e){
			lazy[p] = lazy[p] * v;
			tree[p] = tree[p] * v;
			return;
		}
		int pm = (ps + pe) / 2;
		lazydown(p);
		upd(s, e, ps, pm, 2*p, v);
		upd(s, e, pm+1, pe, 2*p+1, v);
		tree[p] = tree[2*p] + tree[2*p+1];
	}
	mat query(int s, int e, int ps, int pe, int p){
		if(e < ps || pe < s){
			mat v;
			v.init();
			return v;
		}
		if(s <= ps && pe <= e) return tree[p];
		int pm = (ps + pe) / 2;
		lazydown(p);
		return query(s, e, ps, pm, 2*p) + query(s, e, pm+1, pe, 2*p+1);
	}
}seg;

int n, m, a[100005];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	seg.init(1, n, 1, a);
	while(m--){
		int t;
		scanf("%d",&t);
		if(t == 1){
			int s, e, x;
			scanf("%d %d %d",&s,&e,&x);
			mat v = ppow(x);
			seg.upd(s, e, 1, n, 1, v);
		}
		else{
			int s, e;
			scanf("%d %d",&s,&e);
			mat v = seg.query(s, e, 1, n, 1);
			printf("%lld\n", (v.a[1][0] + v.a[1][1]) % mod);
		}
	}
}