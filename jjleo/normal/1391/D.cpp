#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int n, m;
char s[maxn];
int a[5][maxn];
int f[maxn][10];
int ans = 1e9;

int main(){
	scanf("%d%d", &n, &m);
	if(n >= 4 && m >= 4) return printf("-1"), 0;
	if(n == 1 || m == 1) return printf("0"), 0;
	for(int i = 1;i <= n;i++){
		scanf("%s", s + 1);
		if(n <= 3){
			for(int j = 1;j <= m;j++) a[i][j] = s[j] - '0';
		}else{
			for(int j = 1;j <= m;j++) a[j][i] = s[j] - '0';
		}
	}
	if(n > 3) swap(n, m);
	for(int j = 1;j <= m;j++){
		for(int k = 1 << n;~k;k--){
			f[j][k] = 1e9;
			for(int l = 1 << n;~l;l--){
				bool tag = false;
				for(int i = 1;i < n;i++){
					if((((k & (1 << (i - 1))) != 0) + ((k & (1 << i)) != 0) + ((l & (1 << (i - 1))) != 0) + ((l & (1 << i)) != 0)) & 1) continue;
					tag = true;
					break;
				}
				if(tag) continue;
				int sum = 0;
				for(int i = 0;i < n;i++){
					if((((k & (1 << i))) != 0) != a[i + 1][j]) sum++;
				}
				f[j][k] = min(f[j][k], f[j - 1][l] + sum);
			}
			if(j == m) ans = min(ans, f[j][k]);
		}
	}
	printf("%d", ans);
}