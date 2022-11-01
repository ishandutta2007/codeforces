#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("1 ");
		for(int i = 3;i <= n;i++) printf("%d ", i);
		puts("2");
	}
}