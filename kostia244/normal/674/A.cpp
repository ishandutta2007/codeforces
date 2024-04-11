#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 5050;
int mod = 1e9 + 7;
int ans[maxn], cnt[maxn], a[maxn], n;
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		memset(cnt, 0, sizeof cnt);
		pair<int, int> r = {-1, -1};
		for(int j = i; j <= n; j++) {
			r = max(r, {++cnt[a[j]], -a[j]});
			ans[-r.second]++;
		}
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
}