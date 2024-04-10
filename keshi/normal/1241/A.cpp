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

ll q, n;

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		cin >> n;
		if(n == 2) cout << 2;
		else cout << n % 2;
		cout << endl;
	}
	
	return 0;
}