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

ll t, a, b;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> a >> b;
		a = abs(a - b);
		b = 0;
		while(a > b * (b + 1) / 2){
			b++;
		}
		while((b * (b + 1) / 2) % 2 != a % 2) b++;
		cout << b << '\n';
	}
	
	return 0;
}