//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll level = 20;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define s first
#define p second

ll t, m, n, a[maxn], x[maxn], c, ans, k, g, sp[maxn][level];

pll h[maxn];

ll cal(ll l, ll r){
	ll o = r - l, u = 0;
	for(ll i = 0; i < level; i++){
		if((o >> i) & 1){
			u = max(u, sp[l][i]);
			l += (1 << i);
		}
	}
	return u;
}

bool isval(ll p){
	if(c + p > n || p > g) return 0;
	ll j = lower_bound(h, h + m, make_pair(p, -1ll)) - h;
	return (x[j] >= cal(c, c + p));
}

ll bs(){
	ll l = 1, r = n - c + 10, mid;
	while(r - l > 1){
		mid = (l + r) / 2;
		if(isval(mid)){
			l = mid;
		}
		else{
			r = mid;
		}
	}
	return l;
}

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> n;
		k = 0;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
			sp[i][0] = a[i];
			k = max(k, a[i]);
		}
		for(ll j = 1; j < level; j++){
			for(ll i = 0; i < n; i++){
				if(i + (1 << j) - 1 < n){
					sp[i][j] = max(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
				}
			}
		}
		cin >> m;
		g = 0;
		for(ll i = 0; i < m; i++){
			cin >> h[i].p >> h[i].s;
			g = max(g, h[i].s);
		}
		sort(h, h + m);
		x[m] = -1;
		for(ll i = m - 1; i > -1; i--){
			x[i] = max(h[i].p, x[i + 1]);
		}
		if(k > x[0]){
			cout << -1 << '\n';
			continue;
		}
		c = 0;
		ans = 0;
		while(c < n){
			c += bs();
			ans++;
		}
		cout << ans << '\n';
	}
	
	return 0;
}