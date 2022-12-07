#include <bits/stdc++.h>
#define maxn 205

using namespace std;

int n, m, o;
int a[maxn], b[maxn], c[maxn];
int f[maxn][maxn][maxn];
int ans;

inline void Max(int &x, int y){
	x = max(x, y);
}

int main(){
	scanf("%d%d%d", &n, &m, &o);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= m;i++) scanf("%d", &b[i]);
	for(int i = 1;i <= o;i++) scanf("%d", &c[i]);
	sort(a + 1, a + 1 + n), reverse(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m), reverse(b + 1, b + 1 + m);
	sort(c + 1, c + 1 + o), reverse(c + 1, c + 1 + o);
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= m;j++){
			for(int k = 0;k <= o;k++){
				ans = max(ans, f[i][j][k]);
				if(i + 1 <= n && j + 1 <= m) Max(f[i + 1][j + 1][k], f[i][j][k] + a[i + 1] * b[j + 1]);
				if(i + 1 <= n && k + 1 <= o) Max(f[i + 1][j][k + 1], f[i][j][k] + a[i + 1] * c[k + 1]);
				if(j + 1 <= m && k + 1 <= o) Max(f[i][j + 1][k + 1], f[i][j][k] + b[j + 1] * c[k + 1]);
			}
		}
	}
	printf("%d", ans);
}