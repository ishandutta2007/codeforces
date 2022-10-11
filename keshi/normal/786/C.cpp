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

ll n, a[maxn], fen[maxn], ls[maxn], b[maxn], ans[maxn];
vector<ll> vec[maxn];

void upd(ll x, ll y){
	for(x += 5; x < maxn; x += x & -x){
		fen[x] += y;
	}
	return;
}
ll get(ll x){
	ll y = 0;
	for(x += 5; x > 0; x -= x & -x){
		y += fen[x];
	}
	return y;
}

int main(){
    fast_io;
    
    cin >> n;
    for(ll i = 0; i < n; i++){
    	cin >> a[i];
	}
    fill(ls, ls + maxn, n);
	for(ll i = n; i--;){
    	b[i] = ls[a[i]];
    	ls[a[i]] = i;
    	upd(b[i], -1);
    	upd(i, 1);
    	vec[0].pb(i + 1);
	}
	for(ll i = 0; i < n; i++){
		for(ll k : vec[i]){
			ll l = i, r = n + 1, mid;
			while(r - l > 1){
				mid = (l + r) >> 1;
				if(get(mid - 1) <= k) l = mid;
				else r = mid;
			}
			ans[k]++;
			vec[l].pb(k);
		}
		upd(i, -1);
		upd(b[i], 1);
	}
	for(ll i = 1; i <= n; i++){
		cout << ans[i] << " ";
	}
 
    return 0;
}