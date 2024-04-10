//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, a[maxn], b[maxn], l, r, c;
string s;

int main(){
	fast_io;
	
	cin >> n >> s;
	s = ' ' + s;
	for(ll i = 1; i <= n; i++){
		a[i] = a[i - 1];
		b[i] = b[i - 1];
		if(s[i] == '0') a[i] = i;
		if(s[i] == '1') b[i] = i;
	}
	for(ll i = 1; i <= n; i++){
		l = 1;
		c = 0;
		while(l + i - 1 <= n){
			r = l + i - 1;
			if(a[r] < l || b[r] < l){
				c++;
				l += i;	
			}
			else{
				l = min(a[r], b[r]) + 1;
			}
		}
		cout << c << " ";
	}
	
	return 0;
}