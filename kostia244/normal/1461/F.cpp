#pragma GCC optimize("O2,unroll-loops,trapv")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<18, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
string solve(vector<int> a) {
	ll pr = 1;
	int n = a.size();
	for(auto &i : a)
		if(__builtin_mul_overflow(pr, i, &pr)) pr = 1ll<<40;
	if(pr >= 1ll<<40) {
		string s;
		int fi = 0;
		while(fi < n && a[fi] == 1) fi++;
		int la = n-1;
		while(la >= 0 && a[la] == 1) la--;
		for(int i = 0; i < n; i++) {
			s += to_string(a[i]);
			if(i+1-n) {
				if(i < fi || i+1 > la) s += "+";
				else s+="*";
			}
		}
		return s;
	}
	vector<ll> pos{0}, pp{1}, dp(n+1), p(n+1);
	ll cur = 1;
	for(int i = 1; i <= n; i++) {
		int v = a[i-1];
		dp[i] = dp[i-1] + v;
		p[i] = i-1;
		cur *= v;
		pp.push_back(cur);
		//cout << pp[0] << " " << pp[1]<< endl;
		for(auto j : pos) {
			//cout << j << " " << dp.size() << " " << pp.size() << " - " << pp[j] <<  endl;
			dp[i] = max(dp[i], dp[j] + (cur/pp[j]));
			if(dp[i] == dp[j] + (cur/pp[j])) p[i] = j;
			//cout << i << " " << j << " | " << (cur/pp[j]) << " " << dp[j] << " _ " << dp[i]  << endl;
		}
		if(i < n && a[i] > 1) pos.push_back(i);
		//cout << i << " " << dp[i] << " " << p[i] << endl;
	}
	vector<int> cut(n+1);
	int v = n;
	while(v) {
		v = p[v];
		cut[v] = 1;
	}
	string s;
	for(int i = 1; i <= n; i++) {
		int v = a[i-1];
		s += to_string(a[i-1]);
		if(i==n) break;
		if(cut[i]) s += "+";
		else s += "*";
	}
	return s;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &i : a) cin >> i;
	string s;
	cin >> s;
	if(s == "+-" || s == "-+") s = "+";
	if(s.size() == 1) {
		for(int i = 0; i < n; i++)
			cout << a[i] << (i+1==n?"\n":s);
		return 0;
	}
	if(s.size() == 3) s = "+*";
	char c = 0;
	while(s[c] == '*') c++;
	c = s[c];
	if(c != '+') {
	for(int i = 0; i < n; i++) {
		cout << a[i];
		if(i+1 != n) {
			cout << (a[i+1] == 0 ? '-' : '*');
		}
	}
	cout << '\n';
	return 0;
	}
	string ans;
	vector<int> buf;
	for(int i = 0; i < n; i++) {
		if(a[i] == 0) {
			if(!buf.empty()) {
				if(!ans.empty()) ans += "+";
				ans += solve(buf);
			}
			//cout << solve(buf) << "::\n";
			if(!ans.empty()) ans += "+";
			ans += "0";
			buf.clear();
		} else {
			buf.push_back(a[i]);
		}
	}
	if(!buf.empty()) {
			if(!ans.empty()) ans += "+";
			ans += solve(buf);
	}
	cout << ans << '\n';
}