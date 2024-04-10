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

ll n;
string s, t;
map<char, char> mp;

int main(){
    fast_io;
    
    mp['A'] = 'A';
    mp['b'] = 'd';
    mp['H'] = 'H';
    mp['I'] = 'I';
    mp['M'] = 'M';
    mp['O'] = 'O';
    mp['o'] = 'o';
    mp['p'] = 'q';
    mp['U'] = 'U';
    mp['V'] = 'V';
    mp['v'] = 'v';
    mp['W'] = 'W';
    mp['w'] = 'w';
    mp['X'] = 'X';
    mp['x'] = 'x';
    mp['Y'] = 'Y';
    mp['T'] = 'T';
    
    cin >> s;
    n = Sz(s);
    t = s.substr(n / 2);
    s = s.substr(0, (n + 1) / 2);
    reverse(all(t));
    
    n = Sz(s);
    for(ll i = 0; i < n; i++){
    	if(mp[s[i]] != t[i] && mp[t[i]] != s[i]){
    		cout << "NIE";
    		return 0;
		}
	}
	cout << "TAK";
 
    return 0;
}