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
#define pll pair<ll, ll>
#define F first
#define S second

ll q, n, l, r, s, t;

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		cin >> n >> l >> r;
		s = 0;
		t = 1;
		for(ll i = 1; i <= n; i++){
			s += 2 * (n - i);
			if(s >= l){
				s -= 2 * (n - i);
				t = i;
				break;
			}
		}
		bool f = 0;
		if(r == n * (n - 1) + 1) f = 1, r--;
		while(s < r){
			for(ll i = t + 1; i <= n; i++){
				if(++s >= l) cout << t << " ";
				if(s == r) break;
				if(++s >= l) cout << i << " ";
				if(s == r) break;
			}
			t++;
		}
		if(f) cout << 1;
		cout << '\n';
	}
	
	return 0;
}