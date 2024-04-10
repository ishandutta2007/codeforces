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

ll n, x, y, a, b, u, d, l, r, ans;

int main(){
	fast_io;
	
	cin >> n >> x >> y;
	
	for(ll i = 0; i < n; i++){
		cin >> a >> b;
		if(a > x) u++;
		if(a < x) d++;
		if(b > y) r++;
		if(b < y) l++;
	}
	
	ans = max(max(u, d), max(l, r));
	
	cout << ans << endl;
	
	if(u == ans){
		cout << x + 1 << " " << y;
	}
	else if(d == ans){
		cout << x - 1 << " " << y;
	}
	else if(r == ans){
		cout << x << " " << y + 1;
	}
	else if(l == ans){
		cout << x << " " << y - 1;
	}
	
	return 0;
}