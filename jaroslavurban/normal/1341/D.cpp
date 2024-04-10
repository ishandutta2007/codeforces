#ifndef __PROGTEST__
#include <bits/stdc++.h>
using namespace std;
#endif // __PROGTEST__

typedef long long ll;
typedef long double ld;
#define pb(x) push_back(x)
#define ff first
#define ss second
#define vec vector
#define all(x) (x).begin(), (x).end()
#define inf 9223372036854775807
#define mod 998244353
// #define endl '\n'
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);
ll nxt() {ll x; cin >> x; return x;}

// nsolved, kleft
ll dp[2020][2020];
string res;
ll n, k;

vec<string> digits;
ll price[2020][10];
vec<ll> blank[10] = {
	{4},
	{1, 2, 4, 5, 7},
	{2, 6},
	{2, 5},
	{1, 5, 7},
	{3, 5},
	{3},
	{2, 4, 5, 7},
	{},
	{5}
};
ll setprice(ll idx){
	ll o = 0;
	for (ll j = 0; j < 7; ++j) 
		if (digits[idx][j] == '1') ++o;
	for (ll i = 0; i < 10; ++i){
		price[idx][i] = 7 - o - blank[i].size();
		for (auto b: blank[i])
			if (digits[idx][b-1] == '1')
				price[idx][i] = -1;
	}
}

//is possible, looking for replacement
bool solvedp(ll d, ll lft){
	if (d == n && lft == 0) return true;
	if (d == n && lft != 0) return false;
	if (dp[d][lft]) return false;
	for (ll i = 9; i >= 0; --i){
		if (price[d][i] != -1 && lft - price[d][i] >= 0 && solvedp(d+1, lft-price[d][i])){
			res.pb(i + '0');
			return true;
		}
	}
	dp[d][lft] = true;
	return false;
}


void solve(){
	n = nxt(), k = nxt();
	digits.resize(n);
	for (ll i = 0; i < n; ++i){
		cin >> digits[i];
		setprice(i);
	}
	if (solvedp(0, k)){
		reverse(all(res));
		cout << res << endl;;
	} else cout << -1 << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	ll t = 1;
	// cin >> t;
	for (ll i = 0; i < t; ++i){ 
		solve();
	}
}