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

ll n, a[maxn], b[maxn];
string s;
vector<ll> vec;

int main(){
    fast_io;
    
    cin >> n;
    for(ll i = 1; i <= n; i++){
    	cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	cin >> s;
	s = " " + s;
	for(ll i = n; i > 0; i--){
		if(s[i] != s[i - 1]) vec.pb(i);
	}
	ll x = n;
	for(ll i = 0; i < Sz(vec); i++){
		b[vec[i]] = x--;
	}
	for(ll i = 1; i <= n; i++){
		if(b[i] == 0) b[i] = x--;
	}
	for(ll i = 1; i <= n; i++){
		cout << a[b[i]] << " ";
		if((b[i] - n) & 1) cout << char('R' - s[n] + 'L');
		else cout << s[n];
		cout << "\n";
	}
	
    return 0;
}