#include <bits/stdc++.h>
#define maxn 205

using namespace std;

typedef long long ll;

int n;
ll a[maxn][maxn];
pair<ll, int> f[maxn][maxn];

inline ll cal(int x1, int x2, int y1, int y2){
	return a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
}

inline ll cal(int l, int r){
	return cal(1, l - 1, l, r) + cal(l, r, r + 1, n);
}

int fa[maxn];

int dfs(int l, int r){
	if(l == r) return l;
	if(l > r) return 0;
	int mid = f[l][r].second;
	fa[dfs(l, mid - 1)] = fa[dfs(mid + 1, r)] = mid;
	return mid;
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++){
		scanf("%lld", &a[i][j]);
		a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
	}
	for(int len = 2;len <= n;len++){
		for(int i = 1;i + len - 1 <= n;i++){
			int j = i + len - 1;
			f[i][j] = {1e18, 0};
			for(int k = i;k <= j;k++){
				f[i][j] = min(f[i][j], {f[i][k - 1].first + f[k + 1][j].first + cal(i, k - 1) + cal(k + 1, j), k});
			}
		}
	}
	dfs(1, n);
	for(int i = 1;i <= n;i++) printf("%d ", fa[i]);
}