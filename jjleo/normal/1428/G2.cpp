#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

typedef long long ll;

int n, m;
int x;
int F[maxn];
ll f[maxn], g[maxn];
vector<ll> v[maxn];
int l[maxn];

int main(){
	scanf("%d", &n);
	memset(f, -0x3f, sizeof(f)), f[0] = 0;
	for(int i = 0, y = 1;i < 6;i++, y *= 10){
		scanf("%d", &x), F[i] = x;
		int z = 3 * y;
		for(int j = 0;j < z;j++) v[j].clear(), l[j] = 0;
		for(int j = 0;j < maxn;j++){
			int q = j / z, r = j % z;
			while(v[r].size() > l[r] && j - v[r][l[r]] > 1ll * z * 3 * (n - 1)) l[r]++;
			while(v[r].size() > l[r] && f[j] - 1ll * q * x >= f[v[r].back()] - 1ll * v[r].back() / z * x) v[r].pop_back();
			v[r].push_back(j);
			g[j] = 1ll * q * x + f[v[r][l[r]]] - 1ll * v[r][l[r]] / z * x; 
		}
		for(int j = 0;j < maxn;j++) f[j] = g[j];
	}
	//for(int i = 0;i <= 60;i++) printf("%d %lld--\n", i, f[i]);
	for(int i = 0, y = 1;i < 6;i++, y *= 10){
		for(int j = maxn - 1;j;j--){
			for(int k = 1;k <= 9 && j - y * k >= 0;k++){
				f[j] = max(f[j], f[j - y * k] + (k % 3 ? 0 : 1ll * k / 3 * F[i]));//ll 
			}
		}
	}
	scanf("%d", &m);
	while(m--){
		scanf("%d", &x);
		printf("%lld\n", f[x]);
	}
}