#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#include <x86intrin.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;
const int maxn = 4003, mod = 998244353;
void solve() {
	int n, k;
	cin >> n >> k;
	int fi = n+1, l = -1;
	for(int t, i = 1; i <= n; i++) {
		cin >> t;
		if(t > k) fi = min(fi, i), l = max(l, i);
	}
	if(l==-1) cout << n;
	else cout << n - (l-fi+1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
//	cin >> t;
	t = 1;
	while(t--) solve();
}