//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll t, n, x;
vector<ll> a;
string s;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> s;
		n = s.size();
		a.clear();
		x = 0;
		for(ll i = 0; i < n; i++){
			if(s[i] == '0'){
				a.pb(x);
				x = 0;
			}
			else x++;
		}
		a.pb(x);
		sort(a.begin(), a.end(), greater<ll>());
		x = 0;
		for(ll i = 0; i < a.size(); i += 2){
			x += a[i];
		}
		cout << x << '\n';
	}
	
	return 0;
}