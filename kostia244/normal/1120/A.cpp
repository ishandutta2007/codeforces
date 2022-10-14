#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1e6 + 10, mlg = 20, mod = 1e9 + 7;
int n, k, m, s, cnt[maxn], a[maxn], b[maxn], g = 0;
void add(int x) {
	g -= cnt[x]>=b[x];
	cnt[x]++;
	g += cnt[x]>=b[x];
}
void rem(int x) {
	g -= cnt[x]>=b[x];
	cnt[x]--;
	g += cnt[x]>=b[x];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> k >> n >> s;
	for(int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	for(int t, i = 1; i <= s; i++) {
		cin >> t;
		b[t]++;
	}
	for(int i = 1; i <= 500000; i++) g += cnt[i]>=b[i];
	pi ans = {1<<30, -1};
	for(int j = 1, i = 1; i <= m; i++) {
		while(g!=500000&&j<=m)add(a[j++]);
		if(g==500000) {
			int t = (i-1)%k;
			if(j-i>=k) t += (j-i)-k;
			ans = min(ans, {t, i});
		}
		rem(a[i]);
	}
	if(ans.first>m||m-ans.first<n*k) return cout << -1, 0;
	cout << ans.first << '\n';
	for(int i = 1; i < (ans.second%k); i++)
		cout << i << " ";
	g = 0;
	for(int i = 1; i <= 500000; i++) cnt[i] = 0, g += cnt[i]>=b[i];
	for(int rr = ans.first - (ans.second-1)%k, i = ans.second;; i++) {
		add(a[i]);
		if(cnt[a[i]]>b[a[i]]&&rr) rr--, cout << i << " ";
		if(g==500000) break;
	}
	return 0;
}