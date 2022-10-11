//In the name of GOD
//Hello Yellow
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll a, b, c, d, e, f, ans;

int main(){
	fast_io;
	
	cin >> a >> b >> c >> d >> e >> f;
	
	for(ll i = 0; i <= a; i++){
		d -= i;
		if(d >= 0){
			ans = max(ans, i * e + min(b, min(c, d)) * f);
		}
		d += i;
	}
	
	cout << ans;
	
	return 0;
}