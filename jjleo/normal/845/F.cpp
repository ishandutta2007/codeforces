#include <bits/stdc++.h>
#define maxn 255
using namespace std;

const int p = 1e9 + 7;

int n, m;
char s[maxn][maxn], t[maxn][maxn];
int f[2][1 << 14][2][2];

inline void add(int &x, int y){
	x += y;
	if(x >= p) x -= p;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n;i++) scanf("%s", s[i]);
	if(m > 14){
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				t[j][i] = s[i][j];
			} 
		}
		swap(n, m);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				s[i][j] = t[i][j];
			} 
		}
	}
	int x = 1, sup = (1 << m) - 1;
	f[0][0][0][0] = 1;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++, x ^= 1){
			memset(f[x], 0, sizeof(f[x]));
			for(int b = 0;b <= sup;b++){
				for(int k = 0;k <= 1;k++){
					for(int l = 0;l <= 1;l++){
						if(!f[x ^ 1][b][k][l]) continue;
						if(s[i][j] == 'x'){
							add(f[x][((b | (1 << j)) ^ (1 << j))][0][l], f[x ^ 1][b][k][l]);
						}else{
							int y = j ? k : 0;
							if(y || (b & (1 << j))) add(f[x][b][y][l], f[x ^ 1][b][k][l]);
							else if(!l) add(f[x][b][0][1], f[x ^ 1][b][k][l]);
							add(f[x][b | (1 << j)][1][l], f[x ^ 1][b][k][l]);
						}
					}
				}
			}
		}
	}
	x ^= 1;
	int ans = 0;
	for(int i = 0;i <= sup;i++){
		for(int j = 0;j <= 1;j++){
			for(int k = 0;k <= 1;k++){
				add(ans, f[x][i][j][k]);
			}
		}
	}
	printf("%d", ans);
}