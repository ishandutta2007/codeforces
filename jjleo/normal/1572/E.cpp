#include <bits/stdc++.h>
#define maxn 205

using namespace std;

typedef long long ll;

int n, k;
int x[maxn], y[maxn];
pair<int, ll> f[maxn][maxn];

inline ll S(int i, int j, int k){
	return abs(1ll * (x[i] - x[j]) * (y[j] - y[k]) - 1ll * (x[j] - x[k]) * (y[i] - y[j]));
}

bool check(ll s){
	for(int i = 1;i + 2 <= n;i++){
		if(S(i, i + 1, i + 2) >= s) f[i][i + 2] = {1, 0};
		else f[i][i + 2] = {0, S(i, i + 1, i + 2)}; 
	}
	for(int len = 4;len <= n;len++){
		for(int i = 1;i + len - 1 <= n;i++){
			int j = i + len - 1;
			f[i][j] = {0, 0};
			for(int k = i + 1;k <= j - 1;k++){
				int x = f[i][k].first + f[k][j].first;
				ll y = S(i, j, k) + f[i][k].second + f[k][j].second;
				if(y >= s) y = 0, x++;
				f[i][j] = max(f[i][j], {x, y});
			}
		}
	}
	return f[1][n].first >= k + 1;
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++) scanf("%d%d", &x[i], &y[i]);
	ll l = 1, r = 8e16, mid;
	while(l < r){
		mid = (l + r >> 1) + 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%lld", l);
}