#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, x, y, k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &x, &y, &k);
		printf("%lld\n", (1ll * y * k + k - 1 + x - 2) / (x - 1) + k);
	} 
}