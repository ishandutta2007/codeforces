#include <bits/stdc++.h>
#define maxn 505

using namespace std;

int a[4][maxn][maxn];
int b[maxn >> 1][maxn][maxn];

int n, m, q;
char s[maxn];

inline int suma(int k, int x, int y, int xx, int yy){
	return a[k][xx][yy] - a[k][x - 1][yy] - a[k][xx][y - 1] + a[k][x - 1][y - 1];
}

inline int sumb(int k, int x, int y, int xx, int yy){
	if(!(x <= xx && y <= yy)) return 0;
	return b[k][xx][yy] - b[k][x - 1][yy] - b[k][xx][y - 1] + b[k][x - 1][y - 1];
}

int main(){
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1;i <= n;i++){
		scanf("%s", s + 1);
		for(int j = 1;j <= m;j++){
			for(int k = 0;k < 4;k++) a[k][i][j] = a[k][i - 1][j] + a[k][i][j - 1] - a[k][i - 1][j - 1];
			switch(s[j]){
				case 'R':
					++a[0][i][j];
					break;
				case 'G':
					++a[1][i][j];
					break;
				case 'Y':
					++a[2][i][j];
					break;
				case 'B':
					++a[3][i][j];
					break;			
			}
		} 
	}
	for(int k = 1;k * 2 <= min(n, m);k++){
		for(int i = 1;i + k * 2 - 1 <= n;i++){
			for(int j = 1;j + k * 2 - 1 <= m;j++){
				if(suma(0, i, j, i + k - 1, j + k - 1) == k * k &&
				suma(1, i, j + k, i + k - 1, j + 2 * k - 1) == k * k &&
				suma(2, i + k, j, i + 2 * k - 1, j + k - 1) == k * k &&
				suma(3, i + k, j + k, i + 2 * k - 1, j + 2 * k - 1) == k * k) b[k][i][j] = 1;
				b[k][i][j] += b[k][i - 1][j] + b[k][i][j - 1] - b[k][i - 1][j - 1];
			}
		}
	}
	int x, y, xx, yy;
	while(q--){
		scanf("%d%d%d%d", &x, &y, &xx, &yy);
		int l = 0, r = min(n, m) >> 1, mid;
		while(l < r){
			int mid = (l + r >> 1) + 1;
			if(sumb(mid, x, y, xx - 2 * mid + 1, yy - 2 * mid + 1)) l = mid;
			else r = mid - 1;
		}
		printf("%d\n", 4 * l * l);
	}
	
}