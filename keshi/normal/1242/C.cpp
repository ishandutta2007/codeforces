//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxn = 200;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const int maxm = 15e6;

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

int n, p[maxn];
ll su, s[maxn];
vector<int> a[maxn];
map<ll, int> ind;
bool dp[maxm];
int par[maxm];
pii ans[maxn];

inline cal(int x){
	int y = 0;
	for(int i = 0; i < n; i++){
		if((x >> i) & 1) y += p[i];
	}
	return y;
}
inline void Do(int x){
	int v = ind[x] - 1;
	int vv = v;
	do{
		int y = su - (s[v] - x);
		int u = ind[y] - 1;
		ans[u] = Mp(y, v);
		v = u;
		x = y;
	}while(v != vv);
	return;
}

int main(){
	fast_io;
	
	p[0] = 1;
	for(int i = 1; i < 20; i++){
		p[i] = p[i - 1] * 3;
	}
	
	cin >> n;
	for(int i = 0; i < n; i++){
		int k;
		cin >> k;
		a[i].resize(k);
		for(int j = 0; j < k; j++){
			cin >> a[i][j];
			s[i] += a[i][j];
			ind[a[i][j]] = i + 1;
		}
		su += s[i];
	}
	if(su % n){
		cout << "No\n";
		return 0;
	}
	su /= n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < Sz(a[i]); j++){
			bool ok = 0;
			int vis = 0;
			int v = i;
			ll x = a[i][j];
			while(1){
				x = su - (s[v] - x);
				if(abs(x) > mod) v = -1;
				else v = ind[x] - 1;
				if(v == -1 || (vis & (1 << v))){
					break;
				}
				vis |= (1 << v);
				if(v == i){
					if(x == a[i][j]) ok = 1;
					break;
				}
			}
			if(ok){
				dp[cal(vis)] = 1;
				par[cal(vis)] = a[i][j];
			}
		}
	}
	dp[0] = 1;
	for(int msk = 1; msk < p[n]; msk++){
		int x = msk, y = 0;
		for(int i = 0; i < n; i++){
			if(x % 3) y += (p[i] << 1);
			x /= 3;
		}
		if(y != msk && dp[y - msk] && dp[msk - (y - msk)]){
			dp[y] = 1;
			par[y] = y - msk;
		}
	}
	if(!dp[p[n] - 1]){
		cout << "No\n";
		return 0;
	}
	int x = p[n] - 1;
	while(x){
		int y = par[x];
		Do(par[y]);
		x -= (y << 1);
	}
	cout << "Yes\n";
	for(int i = 0; i < n; i++){
		cout << ans[i].F << " " << ans[i].S + 1 << "\n";
	}
	
	return 0;
}