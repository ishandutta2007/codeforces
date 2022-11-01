#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int a, b, c;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &a, &b, &c);
		printf("%lld\n", 1ll * a + b - 1 + c - 1);
	}
}