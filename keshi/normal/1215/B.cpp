//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a, b, x, y;

int main(){
	fast_io;
	
	cin >> n;
	
	a = 1;
	x++;
	for(ll i = 1; i <= n; i++){
		cin >> b;
		if(b < 0){
			b = -1;
		}
		else{
			b = 1;
		}
		a *= b;
		if(a == -1){
			y++;
		}
		else{
			x++;
		}
	}
	cout << x * y << " " << x * (x - 1) / 2 + y * (y - 1) / 2;
	
	return 0;
}