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

ll n, a[maxn], ps[maxn];
vector<pll> vec;

pll cal(ll i, ll j){
	return Mp(ps[n] - ps[n - j] + ps[i] - ps[i - j - 1] - a[i] * (j + j + 1), j + j + 1);
}

int main(){
    fast_io;
    
    cin >> n;
    for(ll i = 1; i <= n; i++){
    	cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(ll i = 1; i <= n; i++){
		ps[i] = ps[i - 1] + a[i];
	}
	pll mx = Mp(0, 1);
	pll ans;
	for(ll i = 1; i <= n; i++){
		ll l = -1, r = min(i - 1, n - i);
		while(r - l > 1){
			ll mid = (l + r) >> 1;
			pll p1 = cal(i, mid);
			pll p2 = cal(i, mid + 1);
			if(p1.F * p2.S > p2.F * p1.S) r = mid;
			else l = mid;
		}
		pll p = cal(i, r);
		if(mx.F * p.S <= p.F * mx.S){
			mx = p;
			ans = Mp(i, r);
		}
	}
	cout << ans.S * 2 + 1 << "\n";
	for(ll j = ans.S + 1; j--;){
		cout << a[ans.F - j] << " ";
	}
	for(ll j = ans.S; j--;){
		cout << a[n - j] << " ";
	}
 
    return 0;
}