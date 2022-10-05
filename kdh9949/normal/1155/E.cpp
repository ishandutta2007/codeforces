#include <bits/stdc++.h>
using namespace std;

const int N = 15, K = 55, M = 1000003;

int a[K][N], b[N], c[N][N], sel[K], inv[M];
mt19937_64 rng(123);

int rn(int s, int e){
	uniform_int_distribution dst(s, e);
	return dst(rng);
}

int main(){
	for(int i = 0; i < 50; i++){
		int t = rn(0, M - 1);
		printf("? %d\n", t);
		fflush(stdout);
		for(int j = 0, x = 1; j <= 10; j++, x = 1LL * x * t % M)
			a[i][j] = x;
		scanf("%d", a[i] + 11);
	}
	iota(sel, sel + 50, 0);
	inv[1] = 1;
	for(int i = 2; i < M; i++){
		inv[i] = 1LL * (M / i) * (M - inv[M % i]) % M;
	}
	while(1){
		shuffle(sel, sel + 50, rng);
		for(int i = 0; i <= 10; i++){
			for(int j = 0; j <= 11; j++) c[i][j] = a[sel[i]][j];
		}
		for(int i = 0; i <= 10; i++){
			int j; for(j = i; j <= 10; j++) if(c[j][i]) break;
			if(j > i) for(int k = 0; k <= 11; k++) swap(c[i][k], c[j][k]);
			for(int k = 11; k >= 0; k--) c[i][k] = 1LL * c[i][k] * inv[c[i][i]] % M;
			for(int t = 0; t <= 10; t++) if(t != i && c[t][i])
				for(int k = 11; k >= 0; k--) c[t][k] = (c[t][k] + 1LL * (M - c[t][i]) * c[i][k]) % M;
		}
		int val = 1;
		for(int i = 0; i <= 10; i++) b[i] = c[i][11];
		for(int i = 0; i < 50; i++){
			int t = 0;
			for(int j = 0; j <= 10; j++) t = (t + 1LL * a[i][j] * b[j]) % M;
			if(t != a[i][11]){ val = 0; break; }
		}
		if(1) break;
		if(val) break;
	}
	for(int i = 0; i < M; i++){
		int t = 0;
		for(int j = 0, x = 1; j <= 10; j++, x = 1LL * x * i % M)
			t = (t + 1LL * b[j] * x) % M;
		if(!t){
			printf("! %d\n", i);
			return 0;
		}
	}
	puts("! -1");
}