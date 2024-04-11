#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 3e5 + 33, maxk = 1<<11, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, x, y;
vector<array<ll, 2>> a;
void solve(ll R, ll S, ll swp) {
	ll A = -1;
	for(int i = 0; i < n; i++) {
		ll v = a[i][0];
		if(A == -1) {
			ll t = (R+i)/(i+1);
			if(v >= t) {
				A = i+1;
			}
		} else {
			ll t = (S+(i-A))/(i-A+1);
			if(v >= t) {
				cout << "Yes\n";
				if(!swp) {
					cout << A << " " << i-A+1 << '\n';
					for(int j = 0; j < A; j++) cout << a[j][1] << " "; cout << '\n';
					for(int j = A; j <= i; j++) cout << a[j][1] << " "; cout << '\n';
				} else {
					cout << i-A+1 << " " << A << '\n';
					for(int j = A; j <= i; j++) cout << a[j][1] << " "; cout << '\n';
					for(int j = 0; j < A; j++) cout << a[j][1] << " "; cout << '\n';
				}
				exit(0);
			}
		}
	}
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> x >> y;
	a.resize(n);
	for(int i = 0; i < n; i++) cin >> a[i][0], a[i][1] = i+1;
	sort(all(a), greater<>());
	solve(x, y, 0);
	solve(y, x, 1);
	cout << "No\n";
}