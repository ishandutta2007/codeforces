#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, m;
int f[maxn][26];
char s[maxn], t[maxn];
int a[maxn], b[maxn];

int main(){
	scanf("%d%d%s%s", &n, &m, s + 1, t + 1);
	for(int i = n;i;i--){
		for(int j = 0;j < 26;j++){
			if(s[i] - 'a' == j) f[i][j] = i;
			else f[i][j] = f[i + 1][j];
		}
	}
	a[0] = 0;
	for(int i = 1;i <= m;i++) a[i] = f[a[i - 1] + 1][t[i] - 'a'];
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < 26;j++){
			if(s[i] - 'a' == j) f[i][j] = i;
			else f[i][j] = f[i - 1][j];
		}
	}
	b[m + 1] = n + 1;
	for(int i = m;i;i--) b[i] = f[b[i + 1] - 1][t[i] - 'a'];
	int ans = 0;
	for(int i = 2;i <= m;i++) {
		ans = max(ans, b[i] - a[i - 1]);
		ans = max(ans, a[i] - a[i - 1]);
		ans = max(ans, b[i] - b[i - 1]);
	}
	printf("%d", ans);
}