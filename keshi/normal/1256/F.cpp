//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, BIT[maxn];
 
void update(ll x, ll o){
	for(ll i = x; i <= n; i += i & -i){
		BIT[i] += o;
	}
}
 
ll query(ll x){
	ll o = 0;
	for(ll i = x; i > 0; i -= i & -i){
		o += BIT[i];
	}
	return o;
}

ll q, t[26], inv, cnt[26];

string s, d;

vector<ll> v[26], k[26];

bool f, ride;

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		for(ll i = 0; i < 26; i++){
			v[i].clear();
			k[i].clear();
			t[i] = 0;
		}
		cin >> n >> s >> d;
		for(ll i = 0; i < n; i++){
			BIT[i] = 0;
			v[s[i] - 'a'].pb(i);
			k[d[i] - 'a'].pb(i);
		}
		BIT[n] = 0;
		ride = 0;
		f = 0;
		for(ll i = 0; i < 26; i++){
			if(v[i].size() != k[i].size()){
				ride = 1;
			}
			if(v[i].size() > 1){
				f = 1;
			}
		}
		if(ride){
			cout << "NO" << endl;
			continue;
		}
		if(f){
			cout << "YES" << endl;
			continue;
		}
		for(ll i = 0; i < n; i++){
			t[d[i] - 'a'] = n - i;
		}
		
		inv = 0;
		
		for(ll i = 0; i < n; i++){
			inv += query(t[s[i] - 'a'] - 1);
			update(t[s[i] - 'a'], 1);
		}
		if(inv % 2){
			cout << "NO";
		}
		else{
			cout << "YES";
		}
		cout << endl;
	}
	
	return 0;
}