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

ll q, n, p;

string s;
char c;
bool ride;

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		cin >> n >> s;
		vector<ll> a[10];
		for(ll i = 0; i < n; i++){
			a[s[i] - '0'].pb(i);
		}
		p = -1;
		c = '1';
		ride = 0;
		for(ll i = 0; i < 10; i++){
			if(a[i].empty()){
				continue;
			}
			ll j = upper_bound(a[i].begin(), a[i].end(), p) - a[i].begin();
			for(ll k = j; k < a[i].size(); k++){
				s[a[i][k]] = c;
				p = a[i][k];
			}
			if(j != 0){
				if(c == '2'){
					ride = 1;
				}
				c = '2';
			}
			for(ll k = 0; k < j; k++){
				s[a[i][k]] = c;
				p = a[i][k];
			}
		}
		if(ride){
			cout << '-';
		}
		else{
			cout << s;
		}
		cout << endl;
	}
	
	return 0;
}