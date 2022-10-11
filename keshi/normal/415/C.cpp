#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 100;
const long long mod = 1e9 + 7;
const long long inf = 1e18;

typedef long long ll;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, a, b, p;

int main(){
	fast_io;
	
	cin >> n >> k;
	
	if(n == 1){
		if(k == 0){
			cout << 1;
		}
		else{
			cout << -1;
		}
		return 0;
	}
	if(k < n / 2){
		cout << -1;
		return 0;
	}
	
	a = k - n / 2 + 1;
	b = 2 * a;
	
	p = 1;
	
	cout << a << " " << b << " ";
	
	for(ll i = 0; i < n / 2 - 1; i++){
		while(p == a || p == b || p + 1 == a || p + 1 == b){
			p += 2;
		}
		cout << p << " " << p + 1 << " ";
		p += 2;
	}
	
	while(p == a || p == b){
		p++;
	}
	
	if(n % 2){
		cout << p;
	}
	
	return 0;
}