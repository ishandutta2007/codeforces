#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 3e5 + 55, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	ll ans = 0, cur = 0;
	reverse(all(s));
	for(auto i : s) {
		if(i=='b') {
			cur++;
			if(cur>=mod) cur-=mod;
		} else {
			ans += cur;
			cur = cur+cur;
			if(ans>=mod) ans-=mod;
			if(cur>=mod) cur-=mod;
		}
	}
	cout << ans;
	return 0;
}