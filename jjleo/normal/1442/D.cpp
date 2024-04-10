#include <bits/stdc++.h>
#define maxn 3086

using namespace std;

typedef long long ll;

int n, k, t, x;
vector<ll> v[maxn];
ll f[maxn], ans;

void solve(int l, int r){
	if(l == r){
		for(int i = 0;i < v[l].size();i++) ans = max(ans, v[l][i] + f[k - i]);
		return;
	}
	int mid = l + r >> 1;
	ll g[maxn];
	for(int i = 0;i <= k;i++) g[i] = f[i];
	for(int i = mid + 1;i <= r;i++){
		for(int j = k;j - (int)v[i].size() + 1 >= 0;j--){
			f[j] = max(f[j], f[j - (int)v[i].size() + 1] + v[i].back());
		}
	}
	solve(l, mid);
	for(int i = 0;i <= k;i++) f[i] = g[i];
	for(int i = l;i <= mid;i++){
		for(int j = k;j - (int)v[i].size() + 1 >= 0;j--){
			f[j] = max(f[j], f[j - (int)v[i].size() + 1] + v[i].back());
		}
	}
	solve(mid + 1, r);
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++){
		scanf("%d", &t);
		v[i].push_back(0);
		while(t--){
			scanf("%d", &x);
			if(v[i].size() <= k) v[i].push_back(x);
		}
		for(int j = 1;j < v[i].size();j++) v[i][j] += v[i][j - 1];
	}
	memset(f, -0x3f, sizeof(f)), f[0] = 0;
	solve(1, n);
	printf("%lld", ans);
}