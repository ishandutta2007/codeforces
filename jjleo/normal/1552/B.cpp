#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn][5];

inline bool g(int x, int y){
	int cnt = 0;
	for(int i = 0;i < 5;i++) cnt += a[x][i] < a[y][i];
	return cnt >= 3;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) for(int j = 0;j < 5;j++) scanf("%d", &a[i][j]);
		int x = 1;
		for(int i = 2;i <= n;i++) if(g(i, x)) x = i;
		for(int i = 1;i <= n;i++){
			if(x == i) continue;
			if(g(i, x)){
				x = -1;
				break;
			}
		}
		printf("%d\n", x);
	}
}