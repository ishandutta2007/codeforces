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

ll n, x, a[maxn], d, l, r;

string s;

ll cal(char c, char d){
	if(c > d){
		swap(c, d);
	}
	return min(d - c, c - 'a' + 'z' - d + 1);
}

int main(){
	fast_io;
	
	cin >> n >> x >> s;
	x--;
	
	l = inf;
	r = -1;
	
	for(ll i = 0; n - i - 1 > i; i++){
		a[i] = cal(s[i], s[n - i - 1]);
		d += a[i];
		if(a[i]){
			l = min(l, i);
			r = i;
		}
	}
	if(x > (n - 1) / 2){
		x = n - x - 1;
	}
	if(d == 0){
		cout << 0;
		return 0;
	}
	
	if(x > r){
		cout << x - l + d;
		return 0;
	}
	if(x < l){
		cout << r - x + d;
		return 0;
	}
	
	cout << d + r - l + min(r - x, x - l);
	
	return 0;
}