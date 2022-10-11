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

ll n, o;

bool p[maxn];

int main(){
	fast_io;
	
	cin >> n;
	
	if(n == 1) n = 6;
	
	p[1] = 1;
	
	for(ll i = 2; i < maxn; i++){
		if(!p[i]){
			if(n % i == 0){
				if(o != 0){
					cout << 1;
					return 0;
				}
				o = i;
				while(n % i == 0){
					n /= i;
				}
			}
			for(ll j = i * i; j < maxn; j += i){
				p[j] = 1;
			}
		}
	}
	
	if(n != 1){
		if(o != 0){
			cout << 1;
			return 0;
		}
		o = n;
	}
	
	cout << o;
	
	return 0;
}