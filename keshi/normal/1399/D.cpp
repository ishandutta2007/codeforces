//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll t, n, m, c[maxn];
vector<ll> a, b;
string s;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n >> s;
		m = 0;
		a.clear();
		b.clear();
		for(ll i = 0; i < n; i++){
			if(s[i] == '1'){
				if(a.empty()) c[i] = m++;
				else{
					c[i] = a.back();
					a.pop_back();
				}
				b.pb(c[i]);
			}
			if(s[i] == '0'){
				if(b.empty()) c[i] = m++;
				else{
					c[i] = b.back();
					b.pop_back();
				}
				a.pb(c[i]);
			}
		}
		cout << m << '\n';
		for(ll i = 0; i < n; i++){
			cout << c[i] + 1 << " ";
		}
		cout << '\n';
	}
	
	return 0;
}