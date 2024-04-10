#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m; 

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		int a = 0, b = 0, x, y;
		while(m--){
			scanf("%d%d", &x, &y);
			a = max(a, x), b = max(b, y);
		}
		if(a + b > n){
			puts("IMPOSSIBLE");
			continue;
		}
		for(int i = 1;i <= a;i++) printf("R");
		for(int i = 1;i <= b;i++) printf("W");
		for(int i = a + b + 1;i <= n;i++) printf("W");
		puts("");
	}
}