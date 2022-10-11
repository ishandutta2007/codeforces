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
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], b[maxn], t, p;

int main(){
	fast_io;
	
	cin >> n;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	fill(b, b + maxn, 1000000);
	p = 1;
	for(ll i = 1; i <= n; i++){
		if(a[i] > a[i - 1]){
			b[i] = a[i - 1];
			if(t < a[i] - a[i - 1] - 1){
				cout << -1;
				return 0;
			}
			for(ll j = a[i - 1] + 1; j < a[i]; j++){
				while(b[p] != 1000000) p++;
				b[p] = j;
				t--;
			}
		}
		else t++;
	}
	for(ll i = 1; i <= n; i++){
		cout << b[i] << " ";
	}
	
	return 0;
}