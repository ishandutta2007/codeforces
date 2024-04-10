#include <bits/stdc++.h>
using namespace std;

const int N = 100005, K = 55;

int n, m, k, a[N][K], px[N * K], py[N * K], pc, qx[N * K], qy[N * K], qc;
int c[N][K], cc, cv[N * K], v[N][K], vv[N], d[N * K];
vector<int> e[N], re[N];

void f(int x, int y){
	v[x][y] = 1;
	for(int i : e[x]) if(!v[i][(y + 1) % k]) f(i, (y + 1) % k);
	px[++pc] = x;
	py[pc] = y;
}

void g(int x, int y){
	c[x][y] = cc;
	if(a[x][y] && vv[x] != cc){
		vv[x] = cc;
		cv[cc]++;
	}
	qx[++qc] = x;
	qy[qc] = y;
	for(int i : re[x]) if(!c[i][(y + k - 1) % k]) g(i, (y + k - 1) % k);
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0, x, y; i < m; i++){
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		re[y].push_back(x);
	}
	for(int i = 1; i <= n; i++) for(int j = 0; j < k; j++) scanf("%1d", a[i] + j);
	for(int i = 1; i <= n; i++) for(int j = 0; j < k; j++) if(!v[i][j]) f(i, j);
	for(int i = n * k; i >= 1; i--) if(!c[px[i]][py[i]]){ cc++; g(px[i], py[i]); }
	for(int i = n * k; i >= 1; i--){
		int x = qx[i], y = qy[i];
		int z = c[x][y], t = 0;
		for(int j : e[x]) if(c[j][(y + 1) % k] > z) t = max(t, d[c[j][(y + 1) % k]]);
		d[z] = max(d[z], t + cv[z]);
	}
	printf("%d\n", d[c[1][0]]);
}