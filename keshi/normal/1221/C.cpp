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

ll q, a, b, c, x, y;

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		cin >> a >> b >> c;
		x = min(a, min(b, c));
		a -= x;
		b -= x;
		if(a < b){
			swap(a, b);
		}
		y = max(0ll, min((2 * b - a) / 3, min(a / 3, b / 3)));
		a -= 3 * y;
		b -= 3 * y;
		cout << x + y * 2 + min(a / 2, b) << endl;
	}
	
	return 0;
}