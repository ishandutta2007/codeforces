#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e3 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

ll n, s;

bool p[MAXN];

bool f(ll x){
	ll k = 0;
	
	for(ll i = 1; i <= n; i++){
		if(x % i == 0 && !p[i]){
			k++;
		}
	}
	
	return (k == 2);
}

int main(){
	fast_io;
	
	p[1] = 1;
	
	for(ll i = 2; i * i < MAXN; i++){
		if(!p[i]){
			for(ll j = i * i; j < MAXN; j += i){
				p[j] = 1;
			}
		}
	}
	
	cin >> n;
	
	for(ll i = 2; i <= n; i++){
		if(f(i)){
			s++;
		}
	}
	
	cout << s;
	
	return 0;
}