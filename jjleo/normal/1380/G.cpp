#include <bits/stdc++.h>
#define maxn 300086

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

int n;
long long a[maxn];
int inv;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i++) a[i] += a[i - 1];
	inv = fpow(n, p - 2);
	for(int i = 1;i <= n;i++){
		int ans = 0;
		for(int j = n - i, k = 1;j > 0;j -= i, k++){
			ans += 1ll * k * (a[j] - a[max(0, j - i)]) % p;
			if(ans >= p) ans -= p; 
		}
		printf("%d ", 1ll * ans * inv % p);
	}
}