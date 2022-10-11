//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e3 + 100;
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

ll n, p;
string s;

int main(){
    fast_io;
    
    cin >> n >> s;
    if(Sz(s) == 1) s += '.';
    while(Sz(s) < 6) s += '0';
    for(char c : s){
    	if(c != '.') p = p * 10 + (c - '0');
	}
	p = 10000 - p;
    for(ll i = 0; i <= n; i++){
    	ll a = 2 * ((n - i) * (n - i - 1) * (n - i - 2) / 6);
    	ll b = i * ((n - i) * (n - i - 1) / 2);
    	ll c = 2 * (n * (n - 1) * (n - 2) / 6);
    	if(p * c >= (a + b) * 10000){
    		cout << i << "\n";
    		return 0;
		}
	}
 
    return 0;
}