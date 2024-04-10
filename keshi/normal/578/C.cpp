//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n;

ld a[maxn], ps[maxn], s[maxn];

ld cal(ld x){
	ld h = 0;
	for(ll i = n - 1; i > -1; i--){
		ps[i] = ps[i + 1] + a[i] - x;
	}
	for(ll i = n - 1; i > -1; i--){
		s[i] = min(ps[i], s[i + 1]);
		h = max(h, abs(ps[i] - s[i]));
	}
	for(ll i = n - 1; i > -1; i--){
		ps[i] = ps[i + 1] - a[i] + x;
	}
	for(ll i = n - 1; i > -1; i--){
		s[i] = min(ps[i], s[i + 1]);
		h = max(h, abs(ps[i] - s[i]));
	}
	return h;
}

int main(){
	fast_io;
	cout << fixed << setprecision(10);
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	ld l = -1e5, r = 1e5, m1, m2;
	
	for(ll i = 0; i < 100; i++){
		m1 = l + (r - l) / 3;
		m2 = r - (r - l) / 3;
		if(cal(m1) > cal(m2)){
			l = m1;
		}
		else{
			r = m2;
		}
	}
	
	cout << cal(l);
	
	return 0;
}