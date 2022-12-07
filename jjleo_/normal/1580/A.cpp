#include <bits/stdc++.h>
#define maxn 405

using namespace std;

int t, n, m;
char s[maxn][maxn];
int a[maxn][maxn];
int sum[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
		for(int j = 1;j <= m;j++) for(int i = 1;i <= n;i++) a[i][j] = a[i - 1][j] + s[i][j] - '0';
		int ans = 1e9;
		for(int i = 1;i <= n;i++){
			for(int ii = i + 4;ii <= n;ii++){
				int mn = 1e9;
				for(int j = 1;j <= m;j++){
					sum[j] = sum[j - 1] + a[ii - 1][j] - a[i][j] + (s[i][j] != '1') + (s[ii][j] != '1');
					if(j - 3 >= 1) mn = min(mn, -sum[j - 3] + (ii - i - 1) - (a[ii - 1][j - 3] - a[i][j - 3]));
					ans = min(ans, mn + sum[j - 1] + (ii - i - 1) - (a[ii - 1][j] - a[i][j]));
				}
			}
		}
		printf("%d\n", ans);
	}
}