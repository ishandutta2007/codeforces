//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k;

vector<ll> a;

string s, f, d;

int main(){
	fast_io;
	
	cin >> k >> s;
	
	n = s.size();
	
	if(n % k){
		for(ll i = 0; i * k < n; i++){
			cout << 1;
			for(ll j = 1; j < k; j++){
				cout << 0;
			}
		}
		return 0;
	}
	
	f = s.substr(0, k);
	
	for(ll i = 0; i * k < n; i++){
		d += f;
	}
	
	if(d > s){
		cout << d;
		return 0;
	}
	
	for(ll i = k - 1; i > -1; i--){
		a.pb(f[i] - '0');
	}
	a.pb(0);
	
	a[0]++;
	
	for(ll i = 0; i < k; i++){
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}
	
	if(a.back()){
		for(ll i = -1; i * k < n; i++){
			cout << 1;
			for(ll j = 1; j < k; j++){
				cout << 0;
			}
		}
		return 0;
	}
	else{
		for(ll i = 0; i < k; i++){
			f[k - i - 1] = char('0' + a[i]);
		}
	}
	
	for(ll i = 0; i * k < n; i++){
		cout << f;
	}
	
	return 0;
}