#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, r;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &r);
		if(n <= r) printf("%lld\n", 1ll * min(n, r) * (min(n, r) - 1) / 2 + 1);
		else printf("%lld\n", 1ll * min(n, r) * (min(n, r) + 1) / 2);
	}
}