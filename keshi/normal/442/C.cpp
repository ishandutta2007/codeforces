//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 5e5 + 100;
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

ll n, nxt[maxn], prv[maxn], b[maxn], ans, vis[maxn];
pll a[maxn];

int main(){
    fast_io;
    
    cin >> n;
    a[0] = Mp(0, 0);
    a[n + 1] = Mp(0, n + 1);
    for(ll i = 1; i <= n; i++){
    	cin >> a[i].F;
    	a[i].S = i;
	}
	sort(a, a + n + 2);
	for(ll i = 0; i < n + 2; i++){
		b[a[i].S] = i;
	}
	for(ll i = 0; i < n + 2; i++){
		if(a[i].S != n + 1) nxt[i] = b[a[i].S + 1];
		if(a[i].S != 0) prv[i] = b[a[i].S - 1];
	}
	for(ll i = 2; i < n + 2; i++){
		ll nx = nxt[i];
		ll pr = prv[i];
		ll x = min(a[nx].F, a[pr].F);
		if(x < a[i].F){
			vis[i] = 1;
			continue;
		}
		ans += x;
		nxt[pr] = nx;
		prv[nx] = pr;
	}
	for(ll i = n + 1; i > 1; i--){
		ll nx = nxt[i];
		ll pr = prv[i];
		ll x = min(a[nx].F, a[pr].F);
		if(vis[i]){
			ans += x;
		}
	}
	cout << ans;
 
    return 0;
}