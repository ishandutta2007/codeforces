#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define pb push_back
using namespace std;using ll = long long;
const int maxn = 1<<21, mod = 998244353;
int X[maxn], Y[maxn];
void z(int *a, string s) {
	for(int l = 0, r = 0, i = 1; i < s.size(); i++) {
		if(i <= r) a[i] = min(a[i-l], r - i + 1);
		while(i + a[i] < s.size() && s[a[i]] == s[i + a[i]]) a[i]++;
		if(i + a[i] - 1 > r) l = i, r = i + a[i] - 1;
	}
}
string a, l, r;
int cl[maxn], cr[maxn], p[maxn], dp[maxn];
void add(int &a, int b) {
	a += b;
	if(a >= mod) a -= mod;
}
void add(int l, int r, int x) {	
	if(l > r) return;
	add(p[l], x);
	add(p[r+1], x == 0 ? 0 : (mod - x));
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> a >> l >> r;
	z(X, l + "$" + a);
	z(Y, r + "$" + a);
	for(int i = 0; i + l.size() - 1 < a.size(); i++) {
		int t = X[l.size()+1+i];
		if(a[i] != '0')
		cl[i] = (t == l.size() || l[t] <= a[i+t]);
	}
	for(int i = 0; i + r.size() - 1 < a.size(); i++) {
		int t = Y[r.size()+1+i];
		if(a[i] != '0')
		cr[i] = (t == r.size() || r[t] >= a[i+t]);
	}
	dp[0] = 1;
	for(int i = 0; i <= a.size(); i++) {
		if(i) add(p[i], p[i-1]);
		add(dp[i], p[i]);
		if(i == a.size()) break;
		if(a[i] != '0') {
			add(i+l.size()+1, i+r.size()-1, dp[i]);
			if(l.size() != r.size()) {
				if(cr[i]) add(dp[i+r.size()], dp[i]);
				if(cl[i]) add(dp[i+l.size()], dp[i]);
			} else if(cl[i]&&cr[i]) add(dp[i+l.size()], dp[i]);
		} else if((l.size() == 1 && l[0] <= a[i]) && (r.size() > 1 || a[i] <= r[0])) {
			add(dp[i+1], dp[i]);
		}
	}
	cout << dp[a.size()];
}