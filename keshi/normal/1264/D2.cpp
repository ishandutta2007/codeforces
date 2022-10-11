//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e6 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

ll n, a, b, c, f[maxn], fp[maxn], ps1[maxn], ps2[maxn], ans;
string s;

ll C(ll a, ll b){
	if(a < b || b < 0) return 0;
	return f[a] * fp[b] % mod * fp[a - b] % mod;
}

int main(){
    fast_io;
    f[0] = fp[0] = 1;
    for(ll i = 1; i < maxn; i++){
    	f[i] = f[i - 1] * i % mod;
    	fp[i] = pw(f[i], mod - 2);
	}
    
    cin >> s;
    n = Sz(s);
    for(ll i = 0; i < n; i++){
    	if(s[i] == '(') a++;
    	else if(s[i] == ')') b++;
    	else c++;
	}
	for(ll i = c + 1; i--;){
		ps1[i] = ps1[i + 1] + C(c, i);
		if(ps1[i] >= mod) ps1[i] -= mod;
		ps2[i] = ps2[i + 1] + C(c - 1, i);
		if(ps2[i] >= mod) ps2[i] -= mod;
	}
	for(ll i = 0; i < n; i++){
		if(s[i] == '('){
			ans += ps1[max(0ll, i + 1 - b)];
		}
		if(s[i] == '?'){
			ans += ps2[max(0ll, i + 1 - b)];
		}
		if(ans >= mod) ans -= mod;
	}
	cout << ans;
    
 
    return 0;
}