//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a, b, c, x[maxn], o, p;

char s[maxn];

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> s[i] >> x[i];
	}
	
	a = 1023;
	
	for(ll i = 0; i < 10; i++){
		o = 0;
		p = (1ll << i);
		for(ll j = 0; j < n; j++){
			if(s[j] == '|') o |= x[j], p |= x[j];
			if(s[j] == '&') o &= x[j], p &= x[j];
			if(s[j] == '^') o ^= x[j], p ^= x[j];
		}
		if((o >> i) & 1){
			if((p >> i) & 1) c += (1ll << i);
			else b += (1ll << i);
		}
		else{
			if(((p >> i) & 1) == 0) a -= (1ll << i);
		}
	}
	
	cout << "3\n& " << a << "\n^ " << b << "\n| " << c << '\n';
	
	return 0;
}