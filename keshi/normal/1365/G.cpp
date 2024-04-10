//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, a[maxn], b[maxn];
vector<ll> vec[maxn];

int main(){
	fast_io;
	
	cin >> n;
	for(ll i = 0; i < 13; i++){
		a[i] = (i < 6);
	}
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < 13; j++){
			if(a[j]) vec[j].pb(i);
		}
		next_permutation(a, a + 13);
	}
	for(ll i = 0; i < 13; i++){
		if(vec[i].empty()) continue;
		cout << "? " << vec[i].size();
		for(ll j = 0; j < vec[i].size(); j++){
			cout << " " << vec[i][j] + 1;
		}
		cout << '\n';
		cout.flush();
		cin >> b[i];
	}
	cout << "!";
	for(ll i = 0; i < 13; i++){
		a[i] = (i < 6);
	}
	for(ll i = 0; i < n; i++){
		ll x = 0;
		for(ll j = 0; j < 13; j++){
			if(a[j] == 0) x |= b[j];
		}
		cout << " " << x;
		next_permutation(a, a + 13);
	}
	cout << '\n';
	cout.flush();
	
	return 0;
}