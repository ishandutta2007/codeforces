#include <bits/stdc++.h>
#define maxn 2086

using namespace std;

const int p = 1e9 + 7;

typedef long long ll;

int n, m, q;
vector<pair<int, int> > v[maxn];
int x, y, z;
int mx;
bool tag[maxn];
ll f[2][maxn];
ll ans;

pair<ll, ll> g[maxn], now;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p, y >>= 1; 
	}
	return ans;
}

const int inv2 = fpow(2, p - 2);

int main(){
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1;i <= m;i++){
		scanf("%d%d%d", &x, &y, &z);
		v[x].push_back({y, z}), v[y].push_back({x, z});
		mx = max(mx, z);
	}
	for(register int i = 1;i <= n;i++){
		for(int j = 0;j < v[i].size();j++) if(v[i][j].second == mx) tag[i] = true;
	}
	for(register int i = 2;i <= n;i++) f[0][i] = f[1][i] = -1e12;
	for(register int k = 1;k <= m;k++){
		for(register int i = 1;i <= n;i++){
			for(register int j = 0;j < v[i].size();j++){
				f[1][v[i][j].first] = max(f[1][v[i][j].first], f[0][i] + v[i][j].second);
			}
		}
		ll a = 0;
		memcpy(f[0], f[1], sizeof(f[1]));
		for(register int i = 1;i <= n;i++) a = max(a, f[0][i]);
		for(register int i = 1;i <= n;i++){
			if(tag[i] && f[0][i] == a){
				printf("%lld", (ans + (a + a + 1ll * mx * (q - k) % p) * (q - k + 1) % p * inv2 % p) % p);
				return 0;
			}
		}
		ans = (ans + a) % p;
		//printf("%lld--\n", ans);
	}
	for(int i = 1;i <= n;i++){
		g[i].first = f[0][i];
		for(int j = 0;j < v[i].size();j++) g[i].second = max(g[i].second, 1ll * v[i][j].second);
		now = max(now, g[i]);
	}
	ll x = m;
	while(1){
		//printf("%lld--\n", now.second);
		ll y = q + 1;
		int id = 0;
		for(int i = 1;i <= n;i++){
			if(g[i].second <= now.second) continue;
			ll l = m, r = q + 1, mid;
			while(l < r){
				mid = l + r >> 1;
				if(g[i].first + g[i].second * (mid - m) >= now.first + now.second * (mid - m)) r = mid;
				else l = mid + 1; 
			}
			if(l < y) y = l, id = i;
		}
		y--;
		//printf("%d %d %d--\n", x, y, now.second);
		if(y >= q){
			ans = (ans + (now.first * 2 + now.second * (x + 1 - m) % p + now.second * (q - m) % p) * (q - x) % p * inv2 % p) % p;
			break;
		}
		ans = (ans + (now.first * 2 + now.second * (x + 1 - m) % p + now.second * (y - m) % p) * (y - x) % p * inv2 % p) % p;
		now = g[id];//debug:ans 
		//printf("%lld--\n", ans);
		x = y;
	}
	printf("%lld", ans);
	
}