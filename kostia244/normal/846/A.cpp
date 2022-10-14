#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define pb push_back
#include <x86intrin.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 2e5 + 55, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int a[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x = 0, y = 0;
	cin >> n;
	for(int t, i = 0; i < n; i++) cin >> a[i], x += a[i];
	int ans = x;
	for(int i = 0; i < n; i++) {
		x -= a[i];
		y += a[i]^1;
		ans = max(ans, x+y);
	}
	cout << ans;
}