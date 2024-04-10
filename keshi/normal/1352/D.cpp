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

ll t, n, c[maxn], s, a, b, l, r, p, x;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> n;
		for(ll i = 0; i < n; i++){
			cin >> c[i];
		}
		l = 0, r = n - 1, a = b = s = p = 0;
		while(l <= r){
			s++;
			x = 0;
			if(s % 2){
				while(l <= r && x <= p) x += c[l++];
				a += x;
			}
			else{
				while(l <= r && x <= p) x += c[r--];
				b += x;
			}
			p = x;
		}
		cout << s << " " << a << " " << b << '\n';
	}
	
	return 0;
}