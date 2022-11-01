#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int n;
int a[maxn];
ll f[maxn][3];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	if(n == 1) return printf("%d", a[1]), 0;
	memset(f, -0x3f, sizeof(f));
	ll sum = 0;
	f[0][0] = 0;
	for(int i = 1;i <= n;i++){
		if(i == 1){
			f[i][1] = -a[i];
		}else{
			f[i][((i - 1) / 2 + (i & 1)) % 3] = sum + (i & 1 ? -a[i] : a[i]);
			for(int j = 0;j < 3;j++){
				f[i][j] = max(f[i][j], max(f[i - 1][j] + a[i], f[i - 1][(j + 3 - 1) % 3] - a[i]));
				//printf("%d %d %lld--\n", i, j, f[i][j]);
			}
		}
		sum += a[i] * (i & 1 ? 1 : -1);
	}
	printf("%lld", f[n][(1 + 3 - n % 3) % 3]);
}