#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
void solve() {
	ll a, b;
	cin >> a >> b;
	for(int i = 1; a < b && i <= 100; i++) {
		a>>=1;
		a*=3;
	}
	cout << (a>=b?"YES":"NO") << "\n";
}
int main() {
	 ios::sync_with_stdio(0);
	 cin.tie(0);
	 cout.tie(0);
	 ll t;
	 cin >> t;
	 while(t--) solve();
	 return 0;
}