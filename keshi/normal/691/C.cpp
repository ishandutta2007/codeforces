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
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, c;
string s, t;
bool f1, f2;

int main(){
    fast_io;
    
    cin >> t;
    n = Sz(t);
    for(ll i = 0; i < n; i++){
    	if(f2) c++;
    	if(f1 == 0 && t[i] == '0') continue;
    	if(t[i] == '.'){
    		f2 = 1;
    		continue;
		}
    	f1 = 1;
    	s += t[i];
	}
	if(f1 == 0){
		cout << 0;
		return 0;
	}
	c -= Sz(s) - 1;
	while(s.back() == '0'){
		s.pop_back();
	}
	if(Sz(s) == 1){
		if(c == 0){
			cout << s;
			return 0;
		}
		cout << s << "E" << -c;
		return 0;
	}
	if(c == 0) cout << s[0] << "." << s.substr(1);
	else cout << s[0] << "." << s.substr(1) << "E" << -c;
	
    return 0;
}