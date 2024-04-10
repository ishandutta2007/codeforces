#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, q;
char s[maxn];
int f[maxn][26];
int l, r;

int main(){
	scanf("%d%d%s", &n, &q, s + 1);
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < 26;j++){
			f[i][j] = f[i - 1][j] + (s[i] - 'a' == j);
		}
	}
	while(q--){
		scanf("%d%d", &l, &r);
		int ans = 0;
		for(int i = 0;i < 26;i++) ans += (i + 1) * (f[r][i] - f[l - 1][i]);
		printf("%d\n", ans);
	}
}