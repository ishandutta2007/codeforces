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

pair<char, char> p[2];

string s, t;

int main(){
	fast_io;
	
	cin >> k;
	
	while(k--){
		cin >> n >> s >> t;
		c = 0;
		for(ll i = 0; i < n; i++){
			if(s[i] != t[i]){
				if(c < 2){
					p[c].F = s[i];
					p[c].S = t[i];
				}
				c++;
			}
		}
		if(c == 0){
			cout << "YES";
		}
		else{
			if(c == 2){
				if(p[0].F == p[1].F && p[0].S == p[1].S){
					cout << "YES";
				}
				else{
					cout << "NO";
				}
			}
			else{
				cout << "NO";
			}
		}
		cout << endl;
	}
	
	return 0;
}