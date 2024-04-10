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
#define pll pair<ll, ll>
#define F first
#define S second

ll q, n;

string s;

vector<ll> ans;

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		ans.clear();
		cin >> s;
		n = s.size();
		for(ll i = 0; i < n; i++){
			if(i + 4 < n && s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o' && s[i + 3] == 'n' && s[i + 4] == 'e'){
				ans.pb(i + 2);
				i += 4;
			}
			else if(i + 2 < n && s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o'){
				ans.pb(i + 1);
				i += 2;
			}
			else if(i + 2 < n && s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e'){
				ans.pb(i + 1);
				i += 2;
			}
		}
		cout << ans.size() << '\n';
		for(ll i = 0; i < ans.size(); i++){
			cout << ans[i] + 1 << " ";
		}
		cout << '\n';
	}
	
	return 0;
}