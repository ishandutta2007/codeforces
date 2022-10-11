//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll t, n;
string s[maxn];

int main(){
    fast_io;

	cin >> t;
	while(t--){
		cin >> n;
		for(ll i = 0; i < n; i++){
			cin >> s[i];
		}
		ll a = (s[0][1] - '0') + (s[1][0] - '0');
		ll b = (s[n - 1][n - 2] - '0') + (s[n - 2][n - 1] - '0');
		vector<pll> vec;
		if(a == 0){
			if(s[n - 1][n - 2] != '1') vec.pb(Mp(n, n - 1));
			if(s[n - 2][n - 1] != '1') vec.pb(Mp(n - 1, n));
		}
		else if(a == 2){
			if(s[n - 1][n - 2] != '0') vec.pb(Mp(n, n - 1));
			if(s[n - 2][n - 1] != '0') vec.pb(Mp(n - 1, n));
		}
		else if(b == 0){
			if(s[0][1] != '1') vec.pb(Mp(1, 2));
			if(s[1][0] != '1') vec.pb(Mp(2, 1));
		}
		else if(b == 2){
			if(s[0][1] != '0') vec.pb(Mp(1, 2));
			if(s[1][0] != '0') vec.pb(Mp(2, 1));
		}
		else{
			if(s[0][1] != '1') vec.pb(Mp(1, 2));
			if(s[1][0] != '1') vec.pb(Mp(2, 1));
			if(s[n - 1][n - 2] != '0') vec.pb(Mp(n, n - 1));
			if(s[n - 2][n - 1] != '0') vec.pb(Mp(n - 1, n));
		}
		cout << vec.size() << '\n';
		for(pll i : vec){
			cout << i.F << " " << i.S << '\n';
		}
	}

    return 0;
}