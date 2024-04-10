#include <bits/stdc++.h>
#define fo(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;
#define N 234567

int n, anc[20][N], d[N];
int lca(int a, int b) {
	if (d[a] > d[b]) swap(a,b);
	int dif = d[b] - d[a];
	fo(i,0,20) if (dif & (1<<i)) b = anc[i][b];
	for (int i = 19; i >= 0; i--) if (anc[i][a] != anc[i][b]) {
		a = anc[i][a]; b = anc[i][b];
	}
	if (a==b) return a;
	return anc[0][a];
}
int dist(int a, int b) {
	int l = lca(a, b);
	return d[a] + d[b] - 2*d[l];
}
int main() {
	scanf("%d", &n);
	fo(i,2,n+1) scanf("%d", anc[0]+i);
	fo(i,1,20) fo(j,1,n+1) anc[i][j] = anc[i-1][anc[i-1][j]];
	fo(i,2,n+1) d[i] = d[anc[0][i]]+1;
	int a = 1, b = 1, cur = 0;
	fo(i,2,n+1) {
		int ta = dist(a, i), tb = dist(b, i);
		if (ta > cur) {
			b = i; cur = ta;
		} else if (tb > cur) {
			a = i; cur = tb;
		}
//		printf("%d %d %d\n", a, b, cur);
		printf("%d%c", cur, i==n ? '\n' : ' ');
	}

	return 0;
}