#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &x);
		if(n <= 2){
			puts("1");
		}else printf("%d\n", (n - 2 + x - 1) / x + 1);
	}
}