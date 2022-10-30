#include <bits/stdc++.h>
#define maxn 505

using namespace std;

int t, n, k, r, c;
int a[maxn][maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &n, &k, &r, &c);
		for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) a[i][j] = 0;
		for(int i = 0;i < n / k;i++) for(int j = 0;j < n / k;j++){
			for(int l = 1;l <= k;l++){
				a[i * k + l][j * k + l] = 1;
			}
		}
		int delta = 0;
		while(1){
			int cc = c - delta;
			if(cc < 1) cc += n;
			if(a[r][cc] == 1) break;
			delta++;
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				int jj = j - delta;
				if(jj < 1) jj += n;
				printf("%c", a[i][jj] == 1 ? 'X' : '.');
			}
			puts("");
		}
	}
}