//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, p[maxn], ans[maxn], dp[maxn], mx[maxn], xm[maxn];

ll cal(ll x){
	if(ans[x]) return ans[x];
	fill(mx, mx + x + 2, 0);
	fill(xm, xm + x + 2, 0);
	for(ll i = x; i > 0; i--){
		dp[i] = max(mx[i], xm[i] + 1);
		if(xm[p[i]] < dp[i]) swap(xm[p[i]], dp[i]);
		if(xm[p[i]] > mx[p[i]]) swap(xm[p[i]], mx[p[i]]);
	}
	ans[x] = mx[0];
	return ans[x];
}

int main(){
    fast_io;
    
    cin >> n;
    for(ll i = 1; i <= n; i++){
    	cin >> p[i];
    	p[i]--;
	}
	ll i = 1;
	ll s = 1;
	while(s < n){
		ll l = 0, r = n + 1, mid;
		while(r - l > 1){
			mid = (l + r) >> 1;
			if(cal(mid) > i) r = mid;
			else l = mid;
		}
		while(s < r) ans[s++] = i;
		i++;
	}
	for(ll i = 1; i <= n; i++){
		cout << ans[i] << " ";
	}
 
    return 0;
}