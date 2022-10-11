//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 4e5 + 100;
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

ll n, a[maxn], ans, cnt[maxn];
bool ok[maxn];
vector<ll> vec[maxn];

int main(){
    fast_io;
    
    cin >> n;
    for(ll i = 0; i < n; i++){
    	cin >> a[i];
	}
	for(ll i = 1; i < n; i++){
		vec[__gcd(i, n)].pb(i);
	}
	for(ll i = 1; i < n; i++){
		if(vec[i].empty()) continue;
		for(ll j = 0; j < i; j++){
			ll mx = 0;
			for(ll k = j; k < n; k += i){
				mx = max(mx, a[k]);
			}
			for(ll k = j; k < n; k += i){
				ok[k] = (a[k] == mx);
			}
		}
		ll f = 0;
		while(f < n && ok[f]){
			ok[n + f++] = 1;
		}
		if(f == n){
			ans += Sz(vec[i]) * n;
			continue;
		}
		ll l = -1;
		for(ll j = 0; j < n; j++){
			if(!ok[j + f]){
				cnt[j - l]++;
				l = j;
			}
		}
		cnt[n - l]++;
		ll ptr = 0, s = 0;
		for(ll j = 2; j <= n; j++){
			while(ptr < Sz(vec[i]) && j - 1 >= vec[i][ptr]) s += vec[i][ptr++];
			ans += cnt[j] * (j * ptr - s);
			cnt[j] = 0;
		}
	}
	cout << ans;
 
    return 0;
}