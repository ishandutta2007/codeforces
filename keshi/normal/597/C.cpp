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

ll n, k, a[MAXN], BIT[MAXN][12];

void update(ll x, ll p, ll o){
	for(ll i = x; i <= n; i += i & -i){
		BIT[i][o] += p;
	}
}

ll query(ll x, ll o){
	if(o == 0){
		return 1;
	}
	ll ans = 0;
	for(ll i = x; i > 0; i -= i & -i){
		ans += BIT[i][o];
	}
	return ans;
}

int main(){
	fast_io;
	
	cin >> n >> k;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= 11; j++){
			update(a[i], query(a[i] - 1, j - 1), j);
		}
	}
	
	cout << query(n, k + 1);
	
	return 0;
}