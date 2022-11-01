#include <bits/stdc++.h>
#define maxn 100086

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

int n, m;
int a[maxn][25];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) scanf("%d", &a[j][i]);
	int ans = 0, inv = 1;
	for(int i = 1;i <= n;i++) inv = 1ll * inv * i % p;
	inv = fpow(inv, p - 2);
	for(int i = 1;i <= m;i++){
		sort(a[i] + 1, a[i] + 1 + n);
		int sum = 1;
		for(int j = 1;j <= n;j++){
			sum = 1ll * sum * max(0, a[i][j] - j) % p;
		}
		ans = (ans + 1 + p - 1ll * sum * inv % p) % p;
	}
	printf("%d", ans);
}