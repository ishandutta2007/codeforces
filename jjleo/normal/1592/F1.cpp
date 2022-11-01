#include <bits/stdc++.h>
#define maxn 505

using namespace std;

int n, m;
char s[maxn][maxn];
int a[maxn][maxn];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
	for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) for(int ii = 0;ii <= 1;ii++) for(int jj = 0;jj <= 1;jj++) a[i][j] ^= (s[i + ii][j + jj] == 'B');
	int ans = 0;
	for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) ans += a[i][j];
	if(a[n][m]) for(int i = 1;i < n;i++) for(int j = 1;j < m;j++) if(a[i][j] && a[i][m] && a[n][j]) return printf("%d", ans - 1), 0;
	printf("%d", ans);
	
}