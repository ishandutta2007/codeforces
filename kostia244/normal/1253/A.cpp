//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 1e9 + 7;
void solve() {
	int n;
	vi a, b;
	cin >> n;
	a.resize(n);
	for(auto &i : a) cin >> i;
	b.resize(n);
	for(auto &i : b) cin >> i;
	int l = -1, r = -1;
	for(int i = 0; i < n; i++) {
		a[i]-=b[i];
		if(a[i] > 0) {
			cout << "NO\n";
			return;
		}
		if(a[i]) {
			r=i;
			if(l==-1) l = i;
		}
	}
	if(l==-1) {
		cout << "YES\n";
		return;
	}
	for(int i = l+1; i <= r; i++) {
		if(a[i]!=a[l]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}