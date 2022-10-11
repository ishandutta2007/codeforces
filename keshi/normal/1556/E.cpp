//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ll lg = 20;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, q, a[maxn], b[maxn], ps[maxn], mx[maxn][lg], mn[maxn][lg], f[maxn];

ll getmn(ll l, ll r){
	ll x = f[r - l];
	return min(mn[l][x], mn[r - (1 << x)][x]);
}
ll getmx(ll l, ll r){
	ll x = f[r - l];
	return max(mx[l][x], mx[r - (1 << x)][x]);
}

int main(){
	fast_io;
	
	f[1] = 0;
	for(ll i = 2; i < maxn; i++){
		f[i] = f[i / 2] + 1;
	}
	
	cin >> n >> q;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(ll i = 1; i <= n; i++){
		cin >> b[i];
		ps[i] = ps[i - 1] + b[i] - a[i];
	}
	for(ll i = n; i >= 0; i--){
		mn[i][0] = mx[i][0] = ps[i];
		for(ll j = 1; j < lg; j++){
			if(i + (1 << j) > n + 1) break;
			mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
		}
	}
	while(q--){
		ll l, r;
		cin >> l >> r;
		l--;
		if(ps[l] != ps[r]){
			cout << "-1\n";
			continue;
		}
		if(getmn(l, r + 1) < ps[l]){
			cout << "-1\n";
			continue;
		}
		cout << getmx(l, r + 1) - ps[l] << "\n";
	}
	
	return 0;
}