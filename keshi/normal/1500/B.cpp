//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e6 + 100;
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

ll n, m, k, t, w, a[maxn], b[maxn], c[maxn], d[maxn], e[maxn], ps[maxn];

ll get(ll x){
	ll y = x % t;
	return (x / t) * ps[t] + ps[y];
}

int main(){
    fast_io;
    
    cin >> n >> m >> k;
    for(ll i = 0; i < n; i++){
    	cin >> a[i];
	}
	for(ll i = 0; i < m; i++){
		cin >> b[i];
	}
	if(n < m){
		swap(n, m);
		swap(a, b);
	}
	fill(c, c + maxn, -1);
	for(ll i = 0; i < n; i++){
		c[a[i]] = i;
	}
	for(ll i = 0; i < m; i++){
		if(c[b[i]] != -1){
			ll x = (i - c[b[i]]) % m;
			if(x < 0) x += m;
			d[x]++;
		}
	}
	w = n % m;
	ll i = 0;
	do{
		e[t++] = n - d[i];
		i += w;
		if(i >= m) i -= m;
	}while(i);
	for(ll i = 0; i < t; i++){
		ps[i + 1] = ps[i] + e[i];
	}
	ll l = 0, r = 2e12, mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(get(mid) >= k) r = mid;
		else l = mid;
	}
	ll x = (l * n) % m;
	k -= get(l);
	for(ll i = 0; i < n; i++){
		if(a[i] != b[x]) k--;
		if(k == 0){
			cout << l * n + i + 1;
			return 0;
		}
		x++;
		if(x == m) x = 0;
	}
 
    return 0;
}