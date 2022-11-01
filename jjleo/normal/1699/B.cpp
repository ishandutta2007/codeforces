#include <bits/stdc++.h>
#define maxn 105

using namespace std;

int t, n, m;
int a[maxn][maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n / 2;i++) for(int j = 1;j <= m / 2;j++){
			a[i * 2 - 1][j * 2 - 1] = 0 ^ ((i + j) & 1);
			a[i * 2 - 1][j * 2] = 1 ^ ((i + j) & 1);
			a[i * 2][j * 2 - 1] = 1 ^ ((i + j) & 1);
			a[i * 2][j * 2] = 0 ^ ((i + j) & 1);
		}
		for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) printf("%d%c", a[i][j], " \n"[j == m]);
	}
}