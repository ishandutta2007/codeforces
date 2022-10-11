//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n;

ll get(ll x){
	ll y, z;
	cout << "? " << x << '\n';
	cout.flush();
	cin >> y;
	x += n / 2;
	if(x > n) x -= n;
	cout << "? " << x << '\n';
	cout.flush();
	cin >> z;
	return y - z;
	
}

int main(){
	fast_io;
	
	cin >> n;
	if(n < 60){
		for(ll i = 1; i <= n / 2; i++){
			if(get(i) == 0){
				cout << "! " << i << '\n';
				cout.flush();
				return 0;
			}
		}
		cout << "! -1\n";
		cout.flush();
		return 0;
	}
	ll l, r, mid, x;
	x = get(1);
	if(x % 2){
		cout << "! -1\n";
		cout.flush();
		return 0;
	}
	if(x == 0){
		cout << "! 1\n";
		cout.flush();
		return 0;
	}
	if(get(n) == 0){
		cout << "! " << n << '\n';
		cout.flush();
		return 0;
	}
	if(x > 0){
		l = 2;
		r = 1 + n / 2;
	}
	else{
		l = n / 2 + 2;
		r = n;
	}
	while(r - l > 1){
		cout.flush();
		mid = (l + r) / 2;
		if(get(mid) >= 0) l = mid;
		else r = mid;
	}
	cout << "! " << l << '\n';
	cout.flush();
	return 0;
	
	return 0;
}