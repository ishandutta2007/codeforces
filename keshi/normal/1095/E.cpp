//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], b[maxn], ps[maxn], ans;

string s;

int main(){
	fast_io;
	
	cin >> n >> s;
	
	s = ' ' + s;
	
	for(ll i = 1; i <= n; i++){
		ps[i] = ps[i - 1];
		if(s[i] == ')'){
			ps[i]--;
		}
		else{
			ps[i]++;
		}
		a[i] = min(a[i - 1], ps[i]);
	}
	
	b[n] = ps[n];
	
	for(ll i = n - 1; i > 0; i--){
		b[i] = min(b[i + 1], ps[i]);
	}
	
	if(ps[n] == 2){
		for(ll i = 1; i <= n; i++){
			if(s[i] == '(' && a[i - 1] >= 0 && b[i] >= 2) ans++;
		}
	}
	if(ps[n] == -2){
		for(ll i = 1; i <= n; i++){
			if(s[i] == ')' && a[i - 1] >= 0 && b[i] >= -2) ans++;
		}
	}
	
	cout << ans;
	
	return 0;
}