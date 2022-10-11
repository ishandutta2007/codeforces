//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll t, a, b, ps[maxn], p[maxn];

int main(){
	fast_io;
	
	for(ll i = 2; i < maxn; i++){
		if(p[i] == 0){
			p[i] = i;
			for(ll j = i * i; j < maxn; j += i){
				p[j] = i;
			}
		}
	}
	
	for(ll i = 2; i < maxn; i++){
		ps[i] = ps[i / p[i]] + 1;
	}
	
	for(ll i = 2; i < maxn; i++){
		ps[i] += ps[i - 1];
	}
	cin >> t;
	
	while(t--){
		cin >> b >> a;
		cout << ps[b] - ps[a] << '\n';
	}
	
	return 0;
}