#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

const int p = 998244353;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p, y >>= 1;
	}
	return ans;
} 

int t, n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		int sum = 0;
		for(int i = 1;i <= n;i++) sum += a[i];
		if(sum == 0 || sum == n){
			puts("0");
			continue;
		}
		int x = n - sum;
		int z = 0;
		for(int i = 1;i <= x;i++) z += a[i];
		int ans = 0;
		for(int i = 1;i <= z;i++) ans = (ans + 1ll * n * (n - 1) % p * fpow(2ll * i * i % p, p - 2)) % p;
		printf("%d\n", ans);
	}
}