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

ll q, a, b, n, s, c;

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		cin >> a >> b >> n >> s;
		if(s % n > b){
			cout << "NO" << endl;
			continue;
		}
		c = s % n;
		s -= c;
		b -= c;
		a += b / n;
		if(a * n >= s){
			cout << "YES";
		}
		else{
			cout << "NO";
		}
		cout << endl;
	}
	
	return 0;
}