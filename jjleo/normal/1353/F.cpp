#include <bits/stdc++.h>
#define maxn 105

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int t;
int n, m;
ll a[maxn][maxn];
ull f[maxn][maxn];
ull ans;

void solve(ll y){
	//printf("%llu--\n", y);
	ll x = a[1][1];
	memset(f, -1, sizeof(f)), f[0][1] = f[1][0] = x - y;
	a[1][1] = y;
	for(register int i = 1;i <= n;i++){
		for(register int j = 1;j <= m;j++){
			if(a[1][1] + i - 1 + j - 1 > a[i][j]) continue;
			f[i][j] = 1e19 + 1;
			if(f[i - 1][j] != -1) f[i][j] = min(f[i][j], f[i - 1][j]);
			if(f[i][j - 1] != -1) f[i][j] = min(f[i][j], f[i][j - 1]);
			f[i][j] += a[i][j] - (a[1][1] + i - 1 + j - 1);
		}
	}
	a[1][1] = x;
	if(f[n][m] != -1) ans = min(ans, f[n][m]);
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m), ans = 1e19 + 1;
		for(register int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) scanf("%lld", &a[i][j]);
		solve(a[1][1]);
		for(register int i = 1;i <= n;i++){
			for(register int j = 1;j <= m;j++){
				if(a[1][1] + i - 1 + j - 1 > a[i][j]){
					solve(a[i][j] - (i - 1 + j - 1));
				}
			}
		}
		printf("%llu\n", ans);
	} 
}