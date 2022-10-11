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

ll n, q;

string s, t;

bool vis[30], f;

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		cin >> s >> t;
		n = s.size();
		fill(vis, vis + 30, 0);
		for(ll i = 0; i < n; i++){
			vis[s[i] - 'a'] = 1;
		}
		f = 0;
		for(ll i = 0; i < n; i++){
			if(vis[t[i] - 'a']){
				f = 1;
			}
		}
		if(f) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	
	return 0;
}