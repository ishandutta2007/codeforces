#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m, a, b;
int f[200][200];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &n, &m, &a, &b);
		if(n * a != m * b){
			puts("NO");
			continue;
		}
		puts("YES");
		memset(f, 0, sizeof(f));
		int x = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= a;j++){
				x++;
				if(x > m) x = 1;
				f[i][x] = 1;
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				printf("%d", f[i][j]);
			}
			puts("");
		}
	}
}