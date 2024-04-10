#include <bits/stdc++.h>
#define maxn 2086

using namespace std;

int n, m;
long long ans;
char s[maxn][maxn];
int a[maxn][maxn];
int b[maxn][maxn][4];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
	for(int i = 1;i <= n;i++){
		int x = 0, y = 0;
		for(int j = 1;j <= m;j++){
			if(x == s[i][j]) y++;
			else x = s[i][j], y = 0;
			b[i][j][0] = y;
		}
		x = 0, y = 0;
		for(int j = m;j;j--){
			if(x == s[i][j]) y++;
			else x = s[i][j], y = 0;
			b[i][j][1] = y;
		}
	}
	for(int j = 1;j <= m;j++){
		int x = 0, y = 0;
		for(int i = 1;i <= n;i++){
			if(x == s[i][j]) y++;
			else x = s[i][j], y = 0;
			b[i][j][2] = y;
		}
		x = 0, y = 0;
		for(int i = n;i;i--){
			if(x == s[i][j]) y++;
			else x = s[i][j], y = 0;
			b[i][j][3] = y;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			int sum = maxn;
			for(int k = 0;k < 4;k++) sum = min(sum, b[i][j][k]);
			a[i][j] = sum;
		}
	}
	for(int i = 1;i <= n;i++){
		int x = 0;
		for(int j = 1;j <= m;j++){
			b[i][j][0] = x = min(x + 1, a[i][j]);
		}
		x = 0;
		for(int j = m;j;j--){
			b[i][j][1] = x = min(x + 1, a[i][j]);
		}
	}
	for(int j = 1;j <= m;j++){
		int x = 0;
		for(int i = 1;i <= n;i++){
			b[i][j][2] = x = min(x + 1, a[i][j]);
		}
		x = 0;
		for(int i = n;i;i--){
			b[i][j][3] = x = min(x + 1, a[i][j]);
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			int sum = maxn;
			for(int k = 0;k < 4;k++) sum = min(sum, b[i][j][k]);//, printf("%d %d %d %d--\n", i, j, k, b[i][j][k]);
			ans += sum + 1;
		}
	}
	printf("%lld", ans);
}