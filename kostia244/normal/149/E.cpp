#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace  std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 1e5 + 66, sigma = 26, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
string s, t, tr;
int bt[maxn], btr[maxn], dp[maxn];
bool solve() {
	cin >> t;
	if(t.size()<2) return false;
	tr = t;
	reverse(all(tr));
	int i = 0, j = -1;
	bt[0] = -1;
	while(i < t.size()) {
		while(j!=-1&&t[j]!=t[i]) j = bt[j];
		i++, j++;
		bt[i] = j;
	}
	i = 0, j = -1;
	btr[0] = -1;
	while(i < tr.size()) {
		while(j!=-1&&tr[j]!=tr[i]) j = btr[j];
		i++, j++;
		btr[i] = j;
	}
	j = 0;
	for(int i = 0; i < s.size(); i++) {
		while(j!=-1&&t[j]!=s[i]) j = bt[j];
		dp[i] = ++j;
		if(i) dp[i] = max(dp[i-1], dp[i]);
	}
	j = 0;
	int k = 0;
	for(int i = s.size(); i-->1;) {
		while(j!=-1&&tr[j]!=s[i]) j = btr[j];
		k = max(k, ++j);
		if(dp[i-1]+k>=t.size()) return true;
	}
	return false;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> s;
	int m, ans = 0;
	cin >> m;
	while(m--) ans += solve();
	cout << ans;
}