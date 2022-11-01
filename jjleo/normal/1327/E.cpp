#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int p = 998244353;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p;
		y >>= 1;
	}
	return ans;
}

int n;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		if(i == n) return printf("10"), 0;
		if(i == n - 1){
			printf("180 ");
			continue;
		}
		int ans = 1ll * 2 * 9 * fpow(10, n - i - 1) % p;
		ans += 1ll * (n - i - 1) * 81 * fpow(10, n - i - 2) % p;
		if(ans >= p) ans -= p; 
		printf("%d ", 1ll * 10 * ans % p);
	}
}