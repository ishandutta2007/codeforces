#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4.1,sse4.2,popcnt,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
const int maxn = 1<<18;
void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b = {-1, 1};
	for(auto &i : a) cin >> i;
	for(int i = 0; i < n; i++) cout << abs(a[i])*b[i&1] << " "; cout << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}