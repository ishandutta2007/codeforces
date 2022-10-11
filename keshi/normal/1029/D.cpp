#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 100;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, a, b, c, ans, p;

map<ll, ll> m1[maxn];
map<ll, ll> m2[maxn];

int main(){
	fast_io;
	cin >> n >> k;
	for(ll i = 0; i < n; i++){
		cin >> a;
		b = 0;
		p = a;
		while(p){
			p /= 10;
			b++;
		}
		a %= k;
		m2[b][a]++;
		p = a;
		for(int j = 1; j < 11; j++){
			p = (p * 10) % k;
			c = 0;
			if(p) c = k - p;
			m1[j][c]++;
			if(c == a && j == b) ans--;
		}
	}
	for(ll j = 1; j < 11; j++){
	    for(map<ll, ll>::iterator i = m2[j].begin(); i != m2[j].end(); i++){
    		ans += i -> S * m1[j][i -> F];
    	}
	}
	cout << ans;
	return 0;
}