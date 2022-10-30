#include <bits/stdc++.h>
#define maxn 505

using namespace std;

typedef long long ll;

int n, k;
int a[maxn], b[maxn];
ll f[maxn][maxn];
ll sum;

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 0;i < n;i++) scanf("%d%d", &a[i], &b[i]);
	memset(f, -1, sizeof(f)), f[0][0] = 0;
	for(int i = 0;i < n;i++){
		
		for(int j = 0;j <= k;j++){
			if(f[i][j] == -1) continue;
			int jj = sum - f[i][j] * k - j;
			for(int l = 1;l <= a[i] && l < k;l++){
				if(b[i] + l >= k){
					int num1 = j + a[i] - l;
					int num2 = jj + b[i] - (k - l);
					f[i + 1][num1 % k] = max(f[i + 1][num1 % k], f[i][j] + 1 + num1 / k + num2 / k);
				}
			}
			f[i + 1][(j + a[i]) % k] = max(f[i + 1][(j + a[i]) % k], f[i][j] + (j + a[i]) / k + (jj + b[i]) / k);
		}
		sum += a[i] + b[i];
	}
	ll ans = 0;
	for(int i = 0;i <= k;i++) ans = max(ans, f[n][i]);
	printf("%lld", ans);
}