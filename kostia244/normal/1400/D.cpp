#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,fma")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 3022, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int cnt[maxn][maxn];
void solve() {
	int n;
	cin >> n;
	for(int i =1; i <= n; i++)
		for(int j = 1; j <= n; j++) {
			cnt[i][j] = 0;
		}
	vector<int> a(n);
	for(auto &i : a) cin >> i;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			ans += cnt[a[i]][a[j]];
		}
		for(int j = 0; j < i; j++) {
			cnt[a[j]][a[i]]++;
		}
	}
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}