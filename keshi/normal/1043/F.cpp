//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 3e5 + 100;
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

ll n, a[maxn], cnt[maxn], b[maxn], c[maxn];

bool Do(){
	for(ll i = 1; i < maxn; i++){
		for(ll j = i; j < maxn; j += i){
			c[i] += b[j];
		}
	}
	for(ll i = maxn - 1; i > 0; i--){
		b[i] = cnt[i] * c[i];
		for(ll j = i + i; j < maxn; j += i){
			b[i] -= b[j];
		}
	}
	return b[1];
}

int main(){
    fast_io;
    
    ll g = 0;
    cin >> n;
    for(ll i = 0; i < n; i++){
    	cin >> a[i];
    	g = __gcd(g, a[i]);
    	cnt[a[i]]++;
    	b[a[i]]++;
	}
	if(g != 1){
		cout << -1;
		return 0;
	}
	if(cnt[1]){
		cout << 1;
		return 0;
	}
	for(ll i = 1; i < maxn; i++){
		for(ll j = i + i; j < maxn; j += i){
			cnt[i] += cnt[j];
		}
	}
	for(ll i = 0; i < 10; i++){
		if(Do()){
			cout << i + 2;
			return 0;
		}
	}
 
    return 0;
}