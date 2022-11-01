#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

char s[maxn];
int n;
int f[maxn][26];
long long ans;

int main(){
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < 26;j++){
			f[i][j] = f[i - 1][j] + (s[i] == j + 'a');
		}
	}
	for(int i = 0;i < 26;i++) ans = max(ans, 1ll * f[n][i]);
	for(int i = 0;i < 26;i++){
		for(int j = 0;j < 26;j++){
			long long sum = 0;
			for(int k = 1;k <= n;k++){
				if(s[k] == i + 'a') sum += f[n][j] - f[k][j];
			}
			ans = max(ans, sum);
		}
	}
	printf("%lld", ans);
	
}