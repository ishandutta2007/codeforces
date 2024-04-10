//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 3e6 + 100;
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

ll n, m, c[maxn], ans[maxn];

int main(){
    fast_io;
    
    cin >> n;
    for(ll i = 0; i < n; i++){
    	ll x;
    	cin >> x;
    	c[x]++;
	}
	for(ll i = 1; i < maxn; i++){
		for(ll j = 1; i * j < maxn; j++){
			ans[i * j] += c[i] * c[j];
		}
		if(i * i < maxn) ans[i * i] -= c[i];
	}
	for(ll i = 1; i < maxn; i++){
		ans[i] += ans[i - 1];
	}
	cin >> m;
	for(ll i = 0; i < m; i++){
		ll x;
		cin >> x;
		cout << n * (n - 1) - ans[x - 1] << "\n";
	}
 
    return 0;
}