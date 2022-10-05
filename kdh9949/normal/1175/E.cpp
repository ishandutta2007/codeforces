#include <bits/stdc++.h>
using namespace std;

const int N = 500005, L = 20, SZ = 524288;

struct Seg{
	int d[SZ<<1];
	Seg(){ fill(d, d+(SZ<<1), -int(1e9)); }
	void u(int s, int e, int x){
		for(s += SZ, e += SZ; s <= e; s >>= 1, e >>= 1){
			if( s & 1) d[s++] = max(d[s], x);
			if(~e & 1) d[e--] = max(d[e], x);
		}
	}
	int g(int x){
		int r = -int(1e9);
		for(x += SZ; x; x >>= 1) r = max(r, d[x]);
		return r;
	}
} S;

int n, q, s[L][N];

int main(){
	for(int i = 0; i < N; i++) S.u(i, i, i-1);
	scanf("%d%d", &n, &q);
	for(int x, y; n--; ){
		scanf("%d%d", &x, &y); y--;
		S.u(x, y, y);
	}
	for(int i = 0; i < N-1; i++) s[0][i] = S.g(i);
	for(int i = 1; i < L; i++){
		for(int j = 0; j < N; j++)
			s[i][j] = s[i-1][s[i-1][j] + 1];
	}
	for(int x, y; q--; ){
		scanf("%d%d", &x, &y); y--;
		int r = 0;
		for(int i = L-1; i >= 0; i--){
			if(s[i][x] < y){
				x = s[i][x]+1;
				r += (1<<i);
			}
		}
		if(s[0][x] < y) puts("-1");
		else printf("%d\n", r+1);
	}
}