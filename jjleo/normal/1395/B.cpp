#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, m, x, y;

int main(){
	scanf("%d%d%d%d", &n, &m, &x, &y);
	printf("%d %d\n", x, y);
	for(int i = 1;i <= m;i++){
		if(i == y) continue;
		printf("%d %d\n", x, i);
	}
	y = m;
	for(int i = 1;i <= n;i++){
		if(i == x) continue;
		if(y == m){
			for(int j = m;j;j--) printf("%d %d\n", i, j);
			y = 1;
		}else{
			for(int j = 1;j <= m;j++) printf("%d %d\n", i, j);
			y = m;
		}
	}
}