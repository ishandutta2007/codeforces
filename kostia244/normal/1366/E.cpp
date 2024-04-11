#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
const int maxn = 1<<19, maxa = 1e7 + 333, mod = 998244353;
int n, m, b[maxn], a[maxn];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	map<int, int> cnt;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> b[i];
	for(int i = n-1; i; i--) a[i] = min(a[i], a[i+1]), cnt[a[i]]++;
	cnt[a[n]]++;
	int ans = a[1] == b[1];
	for(int i = 2; i <= m; i++) ans = ans * 1ll * cnt[b[i]] % mod;
	cout << ans;
	return 0;
}