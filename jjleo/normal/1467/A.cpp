#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n == 1){
			puts("9");
			continue;
		}
		if(n == 2){
			puts("98");
			continue;
		}
		printf("989");
		for(int i = 0;i < n - 3;i++) printf("%d", i % 10);
		puts("");
	}
}