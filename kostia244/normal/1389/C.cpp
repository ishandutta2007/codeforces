#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse4,popcnt,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<17, mod = 1e9 + 7;
int sl(string s, int a, int b) {
	int ans = 0;
	for(auto i : s) {
		if(i == a) swap(a, b), ans++;
	}
	if(a != b && (ans&1)) ans --;
	return ans;
}
void solve() {
	string s;
	cin >> s;
	for(auto &i : s) i -= '0';
	int ans = 1;
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			ans = max(ans, sl(s, i, j));
	cout << s.size()-ans << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
}