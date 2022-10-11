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

ll n, a, s, c;

bool f;

map<ll, ll> cnt;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a;
		cnt[a]++;
		s += a;
	}
	
	cnt[-1] = 1;
	
	for(map<ll, ll>::iterator i = cnt.begin(); i != cnt.end(); i++){
		if(i -> S > 2) f = 1;
		if(i -> S == 2 && cnt[i -> F - 1]) f = 1;
		c += (i -> S == 2);
	}
	
	if(f || c > 1){
		cout << "cslnb";
	}
	else{
		if((s - n * (n - 1) / 2) % 2){
			cout << "sjfnb";
		}
		else{
			cout << "cslnb";
		}
	}
	
	return 0;
}