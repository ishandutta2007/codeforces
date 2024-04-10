//In the name of God
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 1e5;
const int maxx = 10000;
const ll maxX = 1e17;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}


ll dp[5][maxn], pp[5];

int main(){
	fast_io;
	
	for(int i = 1; i < maxx; i++){
		dp[0][i] = i + i;
	}
	for(int o = 1; o < 5; o++){
		pp[o] = pp[o - 1] * (maxx + 1) + maxx;
		for(int i = 1; i < maxx; i++){
			ll x = i;
			for(int j = 0; j <= i; j++){
				if(x > maxX) break;
				if(x < maxx) x = dp[o - 1][x] + 1;
				else x = x + pp[o] + 1;
			}
			dp[o][i] = x - 1;
		}
	}
	ll l = 0, r = 10004205361450475ll, y;
	int x = 4;
	while(r - l > 1){
		if(x == 0){
			assert(r - l - 1 <= l + 1);
			cout << r - l - 1 << " ";
			for(ll i = l + 1; i < r; i++){
				cout << i << " ";
			}
			cout << "\n";
			cout.flush();
			cin >> y;
			return 0;
		}
		x--;
		vector<ll> vec;
		vec.pb(l);
		ll L;
		if(l + 1 < maxx) L = dp[x + 1][l + 1];
		else L = l + 1 + pp[x + 2];
		while(l + 1 < L){
			if(l + 1 < maxx) l = dp[x][l + 1];
			else l = l + 1 + pp[x + 1];
			vec.pb(l);
		}
		cout << Sz(vec) - 2 << " ";
		for(int i = 1; i + 1 < Sz(vec); i++){
			cout << vec[i] << " ";
		}
		cout << "\n";
		cout.flush();
		ll ans;
		cin >> ans;
		if(ans < 0) return 0;
		l = vec[ans];
		r = vec[ans + 1];
	}
	
	return 0;
}