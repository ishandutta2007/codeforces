#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, m, q, x, y;
int sum[maxn];
int cnt[maxn][25], xum[maxn][25];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%d", &x), sum[x] ^= 1;
	for(int i = 1;i <= m;i++){
		cnt[i][0] = sum[i];
		sum[i] ^= sum[i - 1];
	}
	for(int j = 1;j <= 20;j++){
		for(int i = 1;i + (1 << j) - 1 <= m;i++){
			cnt[i][j] = cnt[i][j - 1] ^ cnt[i + (1 << (j - 1))][j - 1];
			xum[i][j] = xum[i][j - 1] ^ xum[i + (1 << (j - 1))][j - 1] ^ (cnt[i + (1 << (j - 1))][j - 1] << (j - 1));
		}
	}
	scanf("%d", &q);
	while(q--){
		scanf("%d%d", &x, &y);
		int ans = 0;
		for(int i = 20;~i;i--){
			if(x + (1 << i) - 1 <= y){
				ans ^= xum[x][i];
				if(sum[y] ^ sum[x + (1 << i) - 1]) ans ^= 1 << i;
				x += 1 << i;
			}
		}
		printf(ans ? "A" : "B");
	}
}