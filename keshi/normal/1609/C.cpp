//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e6 + 100;
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

ll t, n, e, a[maxn], p[maxn];
vector<ll> vec[maxn];

int main(){
	fast_io;
	
	p[1] = 1;
	for(ll i = 2; i * i < maxn; i++){
		if(p[i]) continue;
		for(ll j = i * i; j < maxn; j += i){
			p[j] = 1;
		}
	}
	cin >> t;
	while(t--){
		cin >> n >> e;
		for(ll i = 0; i < e; i++){
			vec[i].clear();
		}
		for(ll i = 0; i < n; i++){
			cin >> a[i];
			if(a[i] == 1) vec[i % e].pb(1);
			else if(p[a[i]]) vec[i % e].pb(0);
			else vec[i % e].pb(2);
		}
		ll ans = 0;
		for(ll i = 0; i < e; i++){
			for(ll j = 0; j < Sz(vec[i]); j++){
				if(vec[i][j] != 2) continue;
				ll l = j, r = j;
				while(l - 1 >= 0 && vec[i][l - 1] == 1) l--;
				while(r + 1 < Sz(vec[i]) && vec[i][r + 1] == 1) r++;
				ans += (r - j + 1) * (j - l + 1) - 1;
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}