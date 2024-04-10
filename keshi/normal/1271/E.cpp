//In the name of GOD
//Hello Yellow
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, a, b;

ll cal(ll x){
	ll c = 0;
	//cout << "# " << x << endl;
	for(ll i = 2; i * x <= n; i *= 2){
		//cout << x << " * " << i << " - " << x << " * " << i << " + " << i - 1 << endl;
		if(i * x + i - 1 > n) c += n - i * x + 1;
		else c += i;
	}
	//cout << x << " " << c << endl;
	return c;
}

int main(){
	fast_io;
	
	cin >> n >> k;
	
	ll l = 1, r = n + 1, mid;
	
	while(r - l > 1){
		mid = (l + r) / 2;
		if(cal(mid) >= k) l = mid;
		else r = mid;
	}
	
	if(cal(l) >= k && l * 2 <= n) a = l * 2;
	
	l = 0, r = n + 1, mid;
	
	while(r - l > 1){
		mid = (l + r) / 2;
		if(cal(mid * 2 + 1) + 1 >= k && mid * 2 + 1 <= n) l = mid;
		else r = mid;
	}
	
	if(cal(l * 2 + 1) + 1 >= k && l * 2 + 1 <= n) b = l * 2 + 1;
	
	cout << max(a, b);
	
	return 0;
}