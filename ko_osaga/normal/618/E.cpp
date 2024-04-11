#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int MAXN = 300005;

struct mtrx{ double a[2][2]; };
struct vect{ double x, y; };
struct op{
	mtrx A;
	vect B;
}emp, a[MAXN];

mtrx mul(mtrx A, mtrx B){
	mtrx C;
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			C.a[i][j] = A.a[i][0] * B.a[0][j] + A.a[i][1] * B.a[1][j];
		}
	}
	return C;
}

vect mul(mtrx A, vect b){ return (vect){A.a[0][0] * b.x + A.a[0][1] * b.y, A.a[1][0] * b.x + A.a[1][1] * b.y}; }
vect add(vect a, vect b){ return (vect){a.x + b.x, a.y + b.y}; }
op merge(op a, op b){ return (op){mul(a.A, b.A), add(mul(a.A, b.B), a.B)}; }

struct seg{
	op tree[1050000];
	int lim;
	void init(int n, op *a){
		for(lim = 1; lim <= n; lim <<= 1);
		fill(tree, tree + 1050000, emp);
		for(int i=1; i<=n; i++){
			tree[i + lim] = a[i];
		}
		for(int i=lim; i; i--){
			tree[i] = merge(tree[2*i], tree[2*i+1]);
		}
	}
	void update(int x, op v){
		x += lim;
		tree[x] = v;
		while(x > 1){
			x >>= 1;
			tree[x] = merge(tree[2*x], tree[2*x+1]);
		}
	}
}seg;

int main(){
	emp.A.a[0][0] = emp.A.a[1][1] = 1;
	int n, q;
	assert(scanf("%d %d",&n,&q) == 2);
	for(int i=1; i<=n; i++){
		a[i] = emp;
		a[i].B.x = 1;
	}
	seg.init(n, a);
	for(int i=1; i<=q; i++){
		int t, v, x;
		scanf("%d %d %d",&t,&v,&x);
		if(t == 1){
			double cur = hypot(a[v].B.x, a[v].B.y);
			a[v].B.x *= (x + cur) / cur;
			a[v].B.y *= (x + cur) / cur;
			seg.update(v, a[v]);
		}
		else{
			double th = (360 - x) * acos(-1) / 180;
			mtrx A;
			A.a[0][0] = cos(th), A.a[0][1] = -sin(th), A.a[1][0] = sin(th), A.a[1][1] = cos(th);
			a[v].A = mul(A, a[v].A);
			a[v].B = mul(A, a[v].B);
			seg.update(v, a[v]);
		}
		vect ret = seg.tree[1].B;
		printf("%.10f %.10f\n", ret.x, ret.y);
	}
}