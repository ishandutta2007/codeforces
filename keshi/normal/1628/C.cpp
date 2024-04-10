//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 3000;
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

bitset<maxn> b, bb[maxn];
bool vis[maxn];
bool ans[maxn][maxn];
int a[maxn][maxn];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int anp[maxn];

bool ok(int x, int y, int n){
	return (0 <= x && x < n && 0 <= y && y < n);
}
int cal(int x, int y, int n){
	return x * n + y;
}

bool add(bitset<maxn> x){
	for(int i = maxn; i--;){
		if(x[i] == 0) continue;
		if(vis[i]) x ^= bb[i];
		else{
			bb[i] = x;
			vis[i] = 1;
			return 1;
		}
	}
	return 0;
}
void get(bitset<maxn> x){
	for(int i = maxn; i--;){
		if(!vis[i]) continue;
		if(!x[i]) x ^= bb[i], anp[i] = 1;
	}
	return;
}

void solve(int n, int dd){
	if(n > 20){
		solve(n - 8, dd + 4);
		for(int i = 0; i < n; i++){
			ans[1 + dd][i + dd] = 1;
			ans[n - 1 + dd][i + dd] = 1;
		}
		for(int i = 1; i < n - 1; i++){
			ans[2 + dd][i + dd] = 1;
			ans[n - 2 + dd][i + dd] = 1;
			ans[i + dd][1 + dd] = 1;
			ans[i + dd][n - 2 + dd]  = 1;
		}
		for(int i = 3; i < n; i += 2){
			ans[i + dd][0 + dd] = 1;
			ans[i + dd][n - 1 + dd] = 1;
		}
		for(int i = 4; i < n; i += 2){
			ans[i + dd][2 + dd] = 1;
			ans[i + dd][n - 3 + dd] = 1;
		}
		return;
	}
	fill(vis, vis + maxn, 0);
	fill(anp, anp + maxn, 0);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			b = 0;
			for(int k = 0; k < 4; k++){
				if(ok(i + dx[k], j + dy[k], n)){
					b[cal(i + dx[k], j + dy[k], n)] = 1;
				}
			}
			add(b);

		}
	}
	b = 0;
	get(b);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ans[i + dd][j + dd] = anp[cal(i, j, n)];
		}
	}
	return;
}

int main(){
	fast_io;
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){
			fill(ans[i], ans[i] + n, 0);
			for(int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}
		solve(n, 0);
		int x = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(ans[i][j]) x ^= a[i][j];
			}
		}
		cout << x << "\n";
	}
}