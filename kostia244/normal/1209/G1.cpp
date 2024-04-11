#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,popcnt,sse4.1,sse4.2,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<20, mod = 998244353, rt = 565042129, i2 = (mod+1)/2;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, q;
int mpos[maxn], a[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a[i], mpos[a[i]] = i;
	int l = 1, r, to, ans = 0;
	while(l <= n) {
		for(to = l, r = l; r <= to; r++) {
			to = max(to, mpos[a[r]]);
		}
		map<int, int> cnt;
		int mx = 0;
		for(int i = l; i < r; i++) {
			mx = max(mx, ++cnt[a[i]]);
		}
		ans += r-l - mx;
		l = r;
	}
	cout << ans;
}