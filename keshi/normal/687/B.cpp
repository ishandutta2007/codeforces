//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, b, c, a[maxn], cnt[maxn];

int main(){
	fast_io;
	
	cin >> n >> k;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(ll i = 2; i <= k; i++){
		while(k % i == 0){
			k /= i;
			cnt[i]++;
		}
	}
	
	for(ll i = 1; i < maxn; i++){
		if(cnt[i] == 0) continue;
		bool f = 1;
		for(ll j = 0; j < n; j++){
			c = 0;
			b = a[j];
			while(b % i == 0){
				b /= i;
				c++;
			}
			if(c >= cnt[i]) f = 0;
		}
		if(f){
			cout << "No";
			return 0;
		}
	}
	
	cout << "Yes";
	
	return 0;
}