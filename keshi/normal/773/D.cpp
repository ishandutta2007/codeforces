//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 2100;
const ll mod = 1e9 + 7;
const int inf = 1e9 + 100;
const ll INF = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) int((x).size())
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

int n;
ll mn, a[maxn], g[maxn][maxn], dis[maxn];
bool vis[maxn];

int main(){
	fast_io;
	
	cin >> n;
	mn = INF;
	for(int i = 1; i <= n; i++){
		g[i][i] = inf;
		for(int j = i + 1; j <= n; j++){
			cin >> g[i][j];
			g[j][i] = g[i][j];
			mn = min(mn, g[i][j]);
		}
	}
	for(int i = 1; i <= n; i++){
		a[i] = inf;
		for(int j = 1; j <= n; j++){
			a[i] = min(a[i], g[i][j]);
		}
		dis[i] = (a[i] - mn) * 2;
	}
	for(int o = 0; o < n; o++){
		int v = -1;
		for(int i = 1; i <= n; i++){
			if(!vis[i] && (v == -1 || dis[v] > dis[i])) v = i;
		}
		vis[v] = 1;
		for(int i = 1; i <= n; i++){
			dis[i] = min(dis[i], dis[v] + g[v][i] - mn);
		}
	}
	for(int i = 1; i <= n; i++){
		cout << dis[i] + mn * (n - 1) << "\n";
	}
	
	return 0;
}