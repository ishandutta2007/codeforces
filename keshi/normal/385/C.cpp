//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 1e5 + 100;
const ll maxm = 1e7 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a, x, m, l, r, p[maxm], cnt[maxm];

int main(){
	fast_io;
	
	for(ll i = 2; i * i < maxm; i++){
		if(p[i]) continue;
		p[i] = i;
		for(ll j = i * i; j < maxm; j += i){
			p[j] = i;
		}
	}
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a;
		while(a != 1){
			x = p[a];
			if(x == 0) x = a;
			while(a % x == 0){
				a /= x;
			}
			cnt[x]++;
		}
	}
	
	for(ll i = 1; i < maxm; i++){
		cnt[i] += cnt[i - 1];
	}
	
	cin >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> l >> r;
		if(l >= maxm) l = maxm - 1;
		if(r >= maxm) r = maxm - 1;
		cout << cnt[r] - cnt[l - 1] << endl;
	}
	
	return 0;
}