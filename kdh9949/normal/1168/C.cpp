#include <bits/stdc++.h>
using namespace std;

const int N = 300005, L = 19;

int n, q, a[N], d[L], w[L], nx[L*(L-1)/2][N];

inline int c(int x, int y){ return (x >> y) & 1; }

inline int wh(int x, int y){ return (max(x, y) * max(x - 1, y - 1) >> 1) + min(x, y); }

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++){
		scanf("%d", a + i);
		for(int j = 0; j < L; j++) for(int k = j + 1; k < L; k++){
			if(c(a[i], j) && c(a[i], k)) nx[wh(j, k)][i] = i; 
		}
	}
	for(int i = 0; i < L*(L-1)/2; i++){
		nx[i][N-1] = N;
		for(int j = N-2; j; j--) if(!nx[i][j]) nx[i][j] = nx[i][j + 1];
	}
	for(int x, y; q--; ){
		scanf("%d%d", &x, &y);
		fill(d, d + L, N);
		for(int i = 0; i < L; i++) if(c(a[x], i)) d[i] = x;
		fill(w, w + L, 0);
		for(int t = int(min_element(d, d + L) - d); t >= 0; ){
			if(d[t] == N) break;
			w[t] = 1;
			for(int i = 0; i < L; i++) if(i != t) d[i] = min(d[i], nx[wh(t, i)][d[t]]);
			int mi = -1;
			for(int i = 0; i < L; i++) if(!w[i]) if(mi < 0 || d[i] < d[mi]) mi = i;
			t = mi;
		}
		int val = 0;
		for(int i = 0; i < L; i++) if(c(a[y], i) && d[i] <= y){ val = 1; break; }
		if(val) puts("Shi");
		else puts("Fou");
	}
}