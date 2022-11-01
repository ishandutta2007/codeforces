#include <bits/stdc++.h>
#define maxn 1086

using namespace std;

const int p = 998244353;

char s[maxn], t[maxn];
int n, m;
int f[maxn][maxn][2][3];

inline void add(int &x, int y){
	x += y;
	if(x >= p) x -= p; 
}

int main(){
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1), m = strlen(t + 1);
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < m;j++){
			f[i][j][0][0] = 1;
		}
	}
	for(int j = 1;j <= m;j++){
		for(int i = 0;i < n;i++){
			f[i][j][1][1] = 1;
		}
	}
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= m;j++){
			for(int k = 0;k <= 1;k++){
				int x = k == 0 ? s[i] : t[j];
				if(i < n && s[i + 1] != x){
					add(f[i + 1][j][0][0], f[i][j][k][0]);
					add(f[i + 1][j][0][2], f[i][j][k][1]);
					add(f[i + 1][j][0][2], f[i][j][k][2]);
				}
				if(j < m && t[j + 1] != x){
					add(f[i][j + 1][1][1], f[i][j][k][1]);
					add(f[i][j + 1][1][2], f[i][j][k][0]);
					add(f[i][j + 1][1][2], f[i][j][k][2]);
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) for(int k = 0;k <= 1;k++) add(ans, f[i][j][k][2]);
	printf("%d", ans);
}