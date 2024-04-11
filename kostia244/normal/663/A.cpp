#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,popcnt,sse4.1,sse4.2,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<18, mod = 1e9 + 7 , lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
string s;
vi a, r;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll s, sgn = 1, cur = 0;
	char c;
	while(cin >> c, c != '=') {
		if(c == '+') {
			sgn = 1;
		} else if(c == '-') sgn = -1;
		else {
			a.pb(sgn);
			cur += sgn;
		}
	}
	cin >> s;
	for(auto &i : a) {
		while(cur > s && i<0 && abs(i)<s) cur--, i--;
		while(cur < s && i>0 && abs(i)<s) cur++, i++;
	}
	if(cur != s) return cout << "Impossible", 0;
	cout << "Possible\n";
	int first = 1;
	for(auto i : a) {
		if(first) {
			cout << i << " ";
		} else {
			cout << (i<0?"- ":"+ ") << abs(i) << " ";}
			first = 0;
	}
	cout << "= " << s;
	return 0;
}