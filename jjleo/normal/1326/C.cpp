#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

const int p = 998244353;

int n, k, x, last, ans = 1;


int main(){
	scanf("%d%d", &n, &k);
	printf("%lld ", 1ll * (n + n - k + 1) * k / 2);
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		if(x >= n - k + 1){
			if(last) ans = 1ll * ans * (i - last) % p;
			last = i;
		}
	}
	printf("%d", ans);
}