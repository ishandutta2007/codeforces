#include <bits/stdc++.h>
#define maxn 2086

using namespace std;

typedef long long ll;

int n;
int a[maxn][maxn];
pair<int, int> b[maxn * maxn];
int f[maxn], g[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) scanf("%d", &a[i][j]), b[a[i][j]] = {i, j};
	ll ans = 0;
	for(int i = 1;i <= n * n;i++){
		int x = b[i].first, y = b[i].second;
		ans += 1ll * f[x] * g[y];
		f[x]++, g[y]++;
	}
	ll cn2 = n * (n - 1) / 2;
	printf("%lld", 2ll * cn2 * cn2 - ans);
}