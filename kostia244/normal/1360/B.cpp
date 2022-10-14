#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,popcnt")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 5050, mod = 1e9 + 7, i2 = (mod+1)/2;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto &i : a) cin >> i;sort(all(a));
		int ans = 1<<30;
		for(int i =1; i < n; i++) ans = min(ans, a[i]-a[i-1]);
		cout << ans << '\n';
	}
	return 0;
}