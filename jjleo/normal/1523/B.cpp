#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &x);
		printf("%d\n", n * 3);
		for(int i = 1;i <= n;i += 2){
			printf("1 %d %d\n", i, i + 1);
			printf("2 %d %d\n", i, i + 1);
			printf("1 %d %d\n", i, i + 1);
			printf("1 %d %d\n", i, i + 1);
			printf("2 %d %d\n", i, i + 1);
			printf("1 %d %d\n", i, i + 1);
		}
	}
}