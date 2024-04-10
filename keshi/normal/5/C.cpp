//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll maxm = 21;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, ps[maxn], st[maxn][maxm], lg[maxn], ans, cnt;

string s;

vector<ll> v[2 * maxn];

ll mn(ll l, ll r){
	ll t = r - l + 1;
	return min(st[l][lg[t]], st[r - (1 << lg[t]) + 1][lg[t]]);
}

int main(){
	ll l, r, mid;
	fast_io;
	
	lg[1] = 0;
	
	for(ll i = 2; i < maxn; i++) lg[i] = lg[i / 2] + 1;
	
	cin >> s;
	
	n = s.size();
	
	if(s[0] == '(') ps[0] = 1;
	else ps[0] = -1;
	
	for(ll i = 1; i < n; i++){
		if(s[i] == '(') ps[i] = ps[i - 1] + 1;
		else ps[i] = ps[i - 1] - 1;
	}
	
	for(ll i = 0; i < n; i++){
		st[i][0] = ps[i];
	}
	
	for(ll j = 1; j < maxm; j++){
		for(ll i = 0; (i + (1 << j)) < n; i++){
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
	
	for(ll i = 0; i < n; i++){
		v[ps[i] + maxn].pb(i);
		l = -1, r = v[ps[i] + maxn].size() - 1;
		while(r - l > 1){
			mid = (l + r) / 2;
			if(mn(v[ps[i] + maxn][mid], i) >= ps[i]) r = mid;
			else l = mid;
		}
		if(ans < i - v[ps[i] + maxn][r]){
			ans = i - v[ps[i] + maxn][r];
			cnt = 0;
		}
		if(ans == i - v[ps[i] + maxn][r]) cnt++;
	}
	if(ps[n - 1] == 0 && mn(0, n - 1) >= 0){
		ans = n;
		cnt = 1;
	}
	
	if(ans == 0) cnt = 1;
	
	cout << ans << " " << cnt;
	
	return 0;
}