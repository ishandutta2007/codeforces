#include <bits/stdc++.h>
#define maxn 1000086

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

int a[maxn], b[maxn];

int n;
int k;
int x;
int sum, ans;
int invn;

int main(){
	scanf("%d", &n), invn = fpow(n, p - 2);
	for(int i = 1;i <= n;i++){
		scanf("%d", &k);
		sum += k;
		int inv = 1ll * fpow(k, p - 2) * invn % p;
		for(int j = 1;j <= k;j++){
			scanf("%d", &x);
			a[x]++;
			b[x] += inv;
			if(b[x] >= p) b[x] -= p;
		}
	}
	for(int i = 1;i < maxn;i++){
		ans += 1ll * b[i] * invn % p * a[i] % p;
		if(ans >= p) ans -= p;
	} 
	/*printf("%d", 1ll * ans * fpow(1ll * sum * n % p, p - 2) % p);
	for(int i = 1;i <= 20;i++){
		printf("%d--\n", 1ll * 124780545 * i % p);
	}*/
	printf("%d", ans);
}