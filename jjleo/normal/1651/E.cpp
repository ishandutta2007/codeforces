#include <bits/stdc++.h>
#define maxn 3086

using namespace std;

int n;
vector<int> v[maxn];
int x, y;
int a[maxn];
bool vis[maxn];
long long ans;
int m;

void solve(){
	int l = n + 1, r = 0, L = n + 1, R = 0;
	for(int i = 1;i <= m;i++){
		if(a[i] <= n) l = min(l, a[i]), r = max(r, a[i]);
		else L = min(L, a[i] - n), R = max(R, a[i] - n);
	}
	ans += 1ll * m / 2 * l * (n - r + 1) * L * (n - R + 1);
	for(int i = 1;i <= m;i++){
		int l = n + 1, r = 0, L = n + 1, R = 0;
		for(int j = 1;j < m;j++){
			int x = i + j - 1;
			if(x > m) x -= m;
			if(a[x] <= n) l = min(l, a[x]), r = max(r, a[x]);
			else L = min(L, a[x] - n), R = max(R, a[x] - n);
			int y = i - 1;
			if(y == 0) y = m;
			int z = i + j;
			if(z > m) z -= m;
			if(a[y] <= n && l <= a[y] && a[y] <= r) continue;
			if(a[y] > n && L <= a[y] - n && a[y] - n <= R) continue;
			if(a[z] <= n && l <= a[z] && a[z] <= r) continue;
			if(a[z] > n && L <= a[z] - n && a[z] - n <= R) continue;
			int l_ = 1, r_ = n, L_ = 1, R_ = n;
			if(a[y] <= n){
				if(a[y] < l) l_ = max(l_, a[y] + 1);
				else r_ = min(r_, a[y] - 1);
			}else{
				if(a[y] - n < L) L_ = max(L_, a[y] - n + 1);
				else R_ = min(R_, a[y] - n - 1);
			}
			if(a[z] <= n){
				if(a[z] < l) l_ = max(l_, a[z] + 1);
				else r_ = min(r_, a[z] - 1);
			}else{
				if(a[z] - n < L) L_ = max(L_, a[z] - n + 1);
				else R_ = min(R_, a[z] - n - 1);
			}
			ans += 1ll * j / 2 * (l - l_ + 1) * (r_ - r + 1) * (L - L_ + 1) * (R_ - R + 1);
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n * 2;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	for(int i = 1;i <= n * 2;i++) if(!vis[i]){
		int x = i;
		m = 0;
		while(!vis[x]){
			a[++m] = x;
			vis[x] = true;
			for(int j = 0;j < v[x].size();j++){
				int to = v[x][j];
				if(!vis[to]){
					x = to;
					break;
				}
			}
		}
		solve();
	}
	printf("%lld", ans);
}