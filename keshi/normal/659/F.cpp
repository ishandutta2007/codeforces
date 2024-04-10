//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxn = 1024;
const int maxm = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};

int n, m, a[maxn][maxn], sz[maxm], dsu[maxm], cnt, oon;
bool ok[maxn][maxn], vis[maxn][maxn];
pii b[maxm];
ll k;

inline int cal(int x, int y){
	if(0 <= x && x < n && 0 <= y && y < m) return x * m + y;
	return -1;
}

void init(int N){
	for(int i = 0; i < N; i++){
		dsu[i] = i;
		sz[i] = 1;
	}
}
int root(int v){
	if(dsu[v] != v) dsu[v] = root(dsu[v]);
	return dsu[v];
}
void Union(int v, int u){
	v = root(v);
	u = root(u);
	if(v == u) return;
	if(sz[v] < sz[u]) swap(v, u);
	dsu[u] = v;
	sz[v] += sz[u];
	return;
}

void dfs(int x, int y){
	if(cnt == 0) return;
	cnt--;
	vis[x][y] = 1;
	for(int j = 0; j < 4; j++){
		int nx = x + dx[j], ny = y + dy[j];
		if((~cal(nx, ny)) && !vis[nx][ny] && a[nx][ny] >= oon) dfs(nx, ny);
	}
	return;
}

void found(int x, int y){
	oon = a[x][y];
	cnt = k / a[x][y];
	dfs(x, y);
	cout << "YES\n";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(vis[i][j]) cout << a[x][y] << " ";
			else cout << "0 ";
		}
		cout << "\n";
	}
	return;
}

int main(){
	fast_io;
	
	cin >> n >> m >> k;
	init(n * m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			int x = cal(i, j);
			b[x] = Mp(a[i][j], x);
		}
	}
	sort(b, b + n * m);
	reverse(b, b + n * m);
	for(int i = 0; i < n * m; i++){
		int x = b[i].S / m;
		int y = b[i].S % m;
		int z = b[i].S;
		ok[x][y] = 1;
		for(int j = 0; j < 4; j++){
			int nx = x + dx[j], ny = y + dy[j];
			int nz = cal(nx, ny);
			if(nz != -1 && ok[nx][ny]){
				Union(z, nz);
			}
		}
		if(k % b[i].F == 0 && 1ll * sz[root(z)] * b[i].F >= k){
			found(x, y);
			return 0;
		}
	}
	cout << "NO\n";
	
	return 0;
}