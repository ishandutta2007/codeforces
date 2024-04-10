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

ll k, n, c;

vector<pll> v;

bool f, ride;

string s, t;

int main(){
	fast_io;
	
	cin >> k;
	
	while(k--){
		cin >> n >> s >> t;
		v.clear();
		ride = 0;
		for(ll i = 0; i < n; i++){
			if(s[i] != t[i]){
				f = 0;
				for(ll j = i + 1; j < n; j++){
					if(s[j] == s[i]){
						v.pb({j, i});
						swap(s[j], t[i]);
						f = 1;
						break;
					}
				}
				if(f){
					continue;
				}
				f = 0;
				for(ll j = i + 1; j < n; j++){
					if(t[j] == s[i]){
						v.pb({i + 1, j});
						swap(s[i + 1], t[j]);
						v.pb({i + 1, i});
						swap(s[i + 1], t[i]);
						f = 1;
						break;
					}
				}
				if(!f){
					ride = 1;
				}
			}
		}
		if(ride){
			cout << "No" << endl;
			continue;
		}
		cout << "Yes" << endl;
		cout << v.size() << endl;
		for(ll i = 0; i < v.size(); i++){
			cout << v[i].F + 1 << " " << v[i].S + 1 << endl;
		}
	}
	
	return 0;
}