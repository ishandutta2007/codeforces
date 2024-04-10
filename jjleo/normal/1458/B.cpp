#include <bits/stdc++.h>
#define maxn 105

using namespace std;

int n, a, b;
int f[maxn][2 * maxn * maxn];

int main(){
	scanf("%d", &n);
	memset(f, -0x3f, sizeof(f));
	f[0][0] = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d%d", &a, &b), a *= 2, b *= 2;
		for(int j = n;~j;j--){
			for(int k = 2 * maxn * maxn - 1;~k;k--){
				if(k - b >= 0 && j) f[j][k] = max(f[j][k], f[j - 1][k - b] + a);
				if(k - b / 2 >= 0) f[j][k] = max(f[j][k], f[j][k - b / 2]);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		int ans = 0;
		for(int j = 0;j < 2 * maxn * maxn;j++){
			ans = max(ans, min(j, f[i][j]));
		}
		printf("%.10f ", ans / 2.0);
	}
}