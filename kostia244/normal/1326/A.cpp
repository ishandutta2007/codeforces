#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 5e3 + 22, mod = 998244353;
void solve() {
	int n;
	cin >> n;
	if(n==1) {
		cout << "-1\n";
		return;
	}
	for(int i = 1; i <= n-1; i++) {
		if(i<n-1) cout << 2;
		else cout << ((n-1)%3?2:4);
	}
	cout << 3 << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}