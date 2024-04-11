#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
using ll = long long;
using namespace std;
const int maxn = 1<<17;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n;
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	vector<ll> a(n);
	for(auto &i : a) cin >> i;
	if(n == 1) {
		cout << "1 1\n0\n";
		cout << "1 1\n0\n";
		cout << "1 1\n" << -a[0] << '\n';
		exit(0);
	}
	cout << 1 << " " << n << '\n';
	for(int i = 0; i < n; i++) {
		ll t = a[i]%(n-1);
		t = (n-1-t)%(n-1);
		t *= n;
		cout << t << " ";
		a[i] += t;
	}
	cout << '\n';
	cout << 1 << " " << n-1 << '\n';
	for(int i = 0; i+1 < n; i++) {
		cout << -a[i] << " ";
		a[i] = 0;
	}
	cout << '\n';
	cout << 2 << " " << n << '\n';
	for(int i = 1; i < n; i++) {
		cout << -a[i] << " ";
		a[i] = 0;
	}
	cout << '\n';
}