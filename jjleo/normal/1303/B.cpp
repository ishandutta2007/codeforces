#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, g, b;
long long ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &g, &b);
		int x = (n + 1) / 2 / g;
		if((n + 1) / 2 % g == 0){
			ans = 1ll * (x - 1) * (g + b) + g;
		}else{
			ans = 1ll * x * (g + b) + (n + 1) / 2 % g;
		}
		if(ans < n) ans = n;
		printf("%lld\n", ans);
	} 
}