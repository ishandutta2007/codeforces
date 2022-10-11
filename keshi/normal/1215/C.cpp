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

ll n;

vector<ll> a, b;

string s, d;

int main(){
	fast_io;
	
	cin >> n >> s >> d;
	
	for(ll i = 0; i < n; i++){
		if(s[i] != d[i]){
			if(s[i] == 'a'){
				a.pb(i + 1);
			}
			else{
				b.pb(i + 1);
			}
		}
	}
	if((a.size() + b.size()) % 2){
		cout << -1;
		return 0;
	}
	cout << (a.size() + b.size()) / 2 + a.size() % 2 << endl;
	
	for(ll i = 0; i + 1 < a.size(); i += 2){
		cout << a[i] << " " << a[i + 1] << endl;
	}
	for(ll i = 0; i + 1 < b.size(); i += 2){
		cout << b[i] << " " << b[i + 1] << endl;
	}
	
	if(a.size() % 2){
		cout << a.back() << " " << a.back() << endl;
		cout << a.back() << " " << b.back() << endl;
	}
	
	return 0;
}