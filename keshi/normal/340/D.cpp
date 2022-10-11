// In the name of GOD
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n, a[MAXN], BIT[MAXN];

void update(ll x, ll o){
	for(ll i = x; i <= n; i += i & -i){
		BIT[i] = max(BIT[i], o);
	}
}

ll query(ll x){
	ll o = 0;
	for(ll i = x; i > 0; i -= i & -i){
		o = max(o, BIT[i]);
	}
	return o;
}

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(ll i = 1; i <= n; i++){
		update(a[i], query(a[i] - 1) + 1);
	}
	
	cout << query(n);
	
	return 0;
}