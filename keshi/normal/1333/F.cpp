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

ll n, a[maxn], t;

bool r[maxn];

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = n; i > 1; i--){
		a[i] = a[i + 1] + 1;
		for(ll j = 2; i * j <= n; j++){
			if(!r[i * j]) a[i]--;
			r[i * j] = 1;
		}
	}
	
	for(ll i = 1; i <= n; i++){
		while(t < i - 1 + a[i + 1]){
			cout << i << " ";
			t++;
		}
	}
	
	return 0;
}