#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<20, mod = 998244353;
int dist(string s, string t) {
	int f = 0;
	for(int i = 0; i < s.size(); i++) f += s[i] != t[i];
	return f;
}
string conv(int x) {
	string t = to_string(x);
	if(t.size() < 2) t = "0"+t;
	return t;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int tp; cin >> tp;
	string cur; cin >> cur;
	int dst = 1<<30;
	string ans;
	for(int i = tp>12?0:1; i < (tp>12?24:13); i++)
		for(int j = 0; j < 60; j++) {
			string f = conv(i) + ":" + conv(j);
			if(dist(cur, f) < dst) {
				dst = dist(cur, f);
				ans = f;
			}			
		}
	cout << ans << '\n';
}