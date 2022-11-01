#include <bits/stdc++.h>
#define maxn 150
//debug: 
using namespace std;

const int p = 998244353;

int n, n0;
int l[maxn], r[maxn];
int a[maxn];
int f[maxn][maxn], sum[maxn][maxn];

inline int inv(int x){
	int y = p - 2, ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p, y >>= 1;
	}
	return ans;
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d%d", &l[i], &r[i]), a[++n0] = l[i], a[++n0] = ++r[i];
	sort(a + 1, a + 1 + n0);
	n0 = unique(a + 1, a + 1 + n0) - (a + 1);
	for(int i = 1;i <= n;i++){
		l[i] = lower_bound(a + 1, a + 1 + n0, l[i]) - a;
		r[i] = lower_bound(a + 1, a + 1 + n0, r[i]) - a;
	}
	for(int i = 1;i <= n0;i++) sum[0][i] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = n0 - 1;j;j--){
			if(l[i] <= j && j < r[i]){
				int len = a[j + 1] - a[j], C = 1;//debug:lena[r[i]] - a[l[i]] 
				for(int k = 1;k <= i;k++){
					if(!(l[i + 1 - k] <= j && j < r[i + 1 - k])) break;
					C = 1ll * C * (len + k - 1) % p * inv(k) % p;
					f[i][j] += 1ll * C * sum[i - k][j + 1] % p;
					//printf("%d %d %d %d %d--\n", i, j, k, len + k - 1, k);
					if(f[i][j] >= p) f[i][j] -= p;
				}
			}
			//printf("%d %d %d--\n", i, j, f[i][j]);
			sum[i][j] = sum[i][j + 1] + f[i][j];
			if(sum[i][j] >= p) sum[i][j] -= p;
		}
	}
	int ans = sum[n][1];
	for(int i = 1;i <= n;i++) ans = 1ll * ans * inv(a[r[i]] - a[l[i]]) % p;
	printf("%d", ans);
}