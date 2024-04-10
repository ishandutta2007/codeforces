#include <bits/stdc++.h>
using namespace std;

const int N = 200005, SZ = 262144;

struct Seg{
	struct Nod{
		int mn, mx;
		int lm, rm;
		int dia;
	} d[2 * SZ];
	int l[2 * SZ];

	void m(int x){
		Nod a = d[2 * x], b = d[2 * x + 1];
		d[x] = {min(a.mn, b.mn), max(a.mx, b.mx),
			max({a.lm, b.lm, b.mx - 2 * a.mn}),
			max({a.rm, b.rm, a.mx - 2 * b.mn}),
			max({a.dia, b.dia, a.rm + b.mx, a.mx + b.lm})};
	}

	void a(int x, int y){
		l[x] += y;
		d[x] = {d[x].mn + y, d[x].mx + y, d[x].lm - y, d[x].rm - y, d[x].dia};
	}

	void z(int x){
		a(2 * x, l[x]);
		a(2 * x + 1, l[x]);
		l[x] = 0;
	}

	void u(int s, int e, int v, int x = 1, int p = 0, int q = SZ - 1){
		if(e < p || q < s) return;
		if(s <= p && q <= e){
			a(x, v);
			return;
		}
		z(x);
		u(s, e, v, 2 * x, p, p + q >> 1);
		u(s, e, v, 2 * x + 1, p + q + 2 >> 1, q);
		m(x);
	}

	int g(){ return d[1].dia; }
} S;

int n, q;
char s[N];

int main(){
	scanf("%d%d%s", &n, &q, s + 1);
	n = 2 * n - 2;
	for(int i = 1, j = 0; i <= n; i++){
		j += (s[i] == '(' ? 1 : -1);
		S.u(i, i, j);
	}
	printf("%d\n", S.g());
	for(int x, y; q--; ){
		scanf("%d%d", &x, &y);
		if(x > y) swap(x, y);
		swap(s[x], s[y]);
		S.u(x, y - 1, (s[x] == '(' ? 2 : -2));
		printf("%d\n", S.g());
	}
}