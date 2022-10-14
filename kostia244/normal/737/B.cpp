#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<20, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, a, b, k;
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> a >> b >> k;
	string s;cin >> s;
	s.push_back('1');
	int cnt = 0;
	vector<int> r;
	for(int i = 0; i < n; i++) {
		cnt += s[i] == '0';
		if(s[i] == '0' && s[i+1] == '1') r.push_back(cnt), cnt = 0;
	}
	ll cur = 0;
	for(auto &i : r) cur += i/b;
	cur = cur-(a-1);
	cout << cur << endl;
	for(int cc = 0, i = 0; i < n; i++) {
		if(s[i] == '0') cc++;
		if(cur && cc && (cc%b == 0)) s[i] = '1', cur--, cout << i+1 << " ";
		if(s[i] == '1') cc = 0;
	}
	cout << endl;
}