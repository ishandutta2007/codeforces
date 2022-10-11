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

ll n, a[maxn], b, c;

map<ll, ll> cnt;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i] & -a[i]]++;
		if(cnt[a[i] & -a[i]] > c){
			c = cnt[a[i] & -a[i]];
			b = a[i] & -a[i];
		}
	}
	
	cout << n - c << '\n';
	
	for(ll i = 0; i < n; i++){
		if((a[i] & -a[i]) != b) cout << a[i] << " ";
	}
	
	return 0;
}