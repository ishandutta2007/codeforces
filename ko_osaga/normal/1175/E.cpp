#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MAXN = 500005;

int nxt[20][MAXN];
int n, q;

int main(){
	scanf("%d %d",&n,&q);
	iota(nxt[0], nxt[0] + MAXN, 0);
	for(int i=0; i<n; i++){
		int l, r; scanf("%d %d",&l,&r);
		nxt[0][l] = max(nxt[0][l], r);
	}
	for(int i=1; i<MAXN; i++) nxt[0][i] = max(nxt[0][i], nxt[0][i-1]);
	for(int i=1; i<20; i++){
		for(int j=0; j<MAXN; j++){
			nxt[i][j] = nxt[i-1][nxt[i-1][j]];
		}
	}
	while(q--){
		int x, y; scanf("%d %d",&x,&y);
		int ret = 0;
		for(int i=19; i>=0; i--){
			if(nxt[i][x] < y){
				x = nxt[i][x];
				ret += (1<<i);
			}
		}
		if(nxt[0][x] >= y) ret++;
		if(ret > n) puts("-1");
		else printf("%d\n", ret);
	}
}