//In the name of GOD
//Out of competition B-)
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

ll q, n, x, a, b, c, d, e, p, ans;

pll t[maxn];

bool f[maxn];

set<ll> s;

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		ans = 0;
		c = 0;
		d = 0;
		e = 0;
		s.clear();
		cin >> n >> x >> a >> b;
		for(ll i = 0; i < n; i++){
			cin >> f[i];
			if(f[i]) d++;
			else c++;
		}
		for(ll i = 0; i < n; i++){
			cin >> t[i].F;
			s.insert(t[i].F - 1);
			t[i].S = f[i];
		}
		sort(t, t + n);
		s.insert(x);
		p = 0;
		for(set<ll>::iterator it = s.begin(); it != s.end(); it++){
			while(p < n && t[p].F <= *it){
				if(t[p].S){
					d--;
					e += b;
				}
				else{
					c--;
					e += a;
				}
				p++;
			}
			if(e <= *it){
				if(*it - e > a * c){
					if(*it - e - a * c > b * d) ans = max(ans, p + c + d);
					else ans = max(ans, p + c + (*it - e - a * c) / b);
				}
				else{
					ans = max(ans, p + (*it - e) / a);
				}
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}