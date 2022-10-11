//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 30;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, a, ans, x, b, p[maxn];

int main(){
	fast_io;
	
	p[0] = 1;
	for(ll i = 1; i < maxn; i++){
		p[i] = p[i - 1] * 4;
	}
	
	cin >> t;
	
	while(t--){
		cin >> n;
		n--;
		a = n / 3;
		ans = 0;
		for(ll i = 0; i + 1 < maxn; i++){
			x = a;
			b = 0;
			if(x < p[i] / 3) b = 0;
			else{
				if(i) x -= p[i] / 3;
				if(x < p[i]) b = 1;
				else x -= p[i], b = (x % p[i + 1]) / p[i];
			}
			if(b > 0) ans += ((b - 1 + n - 3 * a) % 3 + 1) * p[i];
		}
		cout << ans << '\n';
	}
	
	return 0;
}