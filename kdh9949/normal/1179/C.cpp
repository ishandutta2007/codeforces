#include <bits/stdc++.h>
using namespace std;

const int N = 300005, SZ = 1048576;

struct Seg{
	int d[2*SZ], l[2*SZ];
	void z(int x){
		l[2*x] += l[x]; d[2*x] += l[x];
		l[2*x+1] += l[x]; d[2*x+1] += l[x];
		l[x] = 0;
	}
	void y(int x){ d[x] = min(d[2*x], d[2*x+1]); }
	void u(int s, int e, int v, int x, int p, int q){
		if(e < p || q < s) return;
		if(s <= p && q <= e){
			l[x] += v; d[x] += v;
			return;
		}
		z(x);
		u(s, e, v, 2*x, p, p+q>>1);
		u(s, e, v, 2*x+1, p+q+2>>1, q);
		y(x);
	}
	void u(int s, int e, int v){ u(s, e, v, 1, 0, SZ-1); }
	int g(int x, int p, int q){
		if(p == q) return p;
		z(x);
		if(d[2*x+1] < 0) return g(2*x+1, p+q+2>>1, q);
		return g(2*x, p, p+q>>1);
	}
	int g(){ if(d[1] < 0) return g(1, 0, SZ-1); return -1; }
} S;

int n, m, q, a[N], b[N];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", a + i);
		S.u(0, a[i], -1);
	}
	for(int i = 1; i <= m; i++){
		scanf("%d", b + i);
		S.u(0, b[i], 1);
	}
	scanf("%d", &q);
	for(int x, y, z; q--; ){
		scanf("%d%d%d", &x, &y, &z);
		if(x == 1){
			S.u(0, a[y], 1);
			a[y] = z;
			S.u(0, a[y], -1);
		}
		else{
			S.u(0, b[y], -1);
			b[y] = z;
			S.u(0, b[y], 1);
		}
		printf("%d\n", S.g());
	}
}