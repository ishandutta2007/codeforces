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

ll x, s, a, cnt[100], ans[100], t;

int main(){
	fast_io;
	
	cin >> x >> s;
	
	a = s - x;
	
	if(a % 2 || a < 0){
		cout << -1;
		return 0;
	}
	
	for(ll i = 0; i < 100; i++){
		if(x % 2) cnt[i]++;
		x /= 2;
	}
	
	a /= 2;
	
	for(ll i = 0; i < 100; i++){
		if(a % 2) cnt[i] += 2;
		a /= 2;
	}
	
	for(ll i = 0; i < 100; i++){
		for(ll j = 0; j < cnt[i]; j++){
			ans[j] += (1ll << i);
			t = max(t, j + 1);
		}
	}
	
	cout << t << '\n';
	
	for(ll i = 0; i < t; i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}