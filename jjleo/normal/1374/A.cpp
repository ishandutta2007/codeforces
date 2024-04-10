#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int x, y, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &x, &y, &n);
		printf("%d\n", (n - y) / x * x + y);
	} 
}