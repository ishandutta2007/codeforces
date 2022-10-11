//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const long long inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll q, n, fen[maxn], a[maxn];
string s, t;
vector<ll> vec[30];

void upd(ll x, ll y){
	for(x += 5; x < maxn; x += x & -x){
		fen[x] += y;
	}
}
ll get(ll x){
	ll y = 0;
	for(x += 5; x > 0; x -= x & -x){
		y += fen[x];
	}
	return y;
}

vector<ll> vv;

int main(){
	fast_io;
	vv.reserve(maxn);
	for(ll i = 0; i < 26; i++){
		vec[i].reserve(maxn);
	}
	
	cin >> q;
	while(q--){
		cin >> n >> s >> t;
		for(ll i = 0; i < 26; i++){
			vec[i].clear();
		}
		for(ll i = n; i--;){
			vec[s[i] - 'a'].pb(i);
		}
		long long ans = inf, cnt = 0;
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < ll(t[i] - 'a'); j++){
				if(vec[j].empty()) continue;
				ll x = vec[j].back();
				ans = min(ans, cnt + x - get(x));
			}
			if(vec[t[i] - 'a'].empty()){
				break;
			}
			else{
				ll x = vec[t[i] - 'a'].back();
				cnt += x - get(x);
				upd(x, 1);
				vv.pb(x);
				vec[t[i] - 'a'].pop_back();
			}
		}
		for(ll i : vv){
			upd(i, -1);
		}
		vv.clear();
		if(ans == inf) ans = -1;
		cout << ans << "\n";
	}
	
	return 0;
}