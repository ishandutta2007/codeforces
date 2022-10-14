#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<20, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
string s;
int solve(vector<int> v) {
	int a = 0;
	for(int p = 1; p < s.size(); p++) {
		int cur = 0;
		vector<int> cnt(26);
		for(auto &i : v) cnt[s[(p+i)%s.size()]-'a']++;
		for(auto i : cnt) cur += i==1;
		a = max(a, cur);
	}
	return a;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> s;
	vector<int> f[26];
	for(int i = 0; i < s.size(); i++) f[s[i]-'a'].push_back(i);
	int res = 0;
	for(int i = 0; i < 26; i++) res += solve(f[i]);
	long double ans = res;
	ans /= s.size();
	cout << fixed << setprecision(15) << ans << endl;
}