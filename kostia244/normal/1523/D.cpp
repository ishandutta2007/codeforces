// Problem: D. Love-Hate
// Contest: Codeforces - Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1523/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
int n, m, p, msk[1<<15], cnt[1<<15];
ll a[1<<19];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n >> m >> p;
	for(int i = 0; i < 1<<15; i++) cnt[i] = __builtin_popcount(i);
	for(int i = 0; i < n; i++) {
		char c;
		for(int j = 0; j < m; j++) {
			cin >> c;c-='0';
			a[i] |= ll(c)<<j;
		}
	}
	pair<int, ll> ans = {0, 0};
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	for(int iter = 100; iter--;) {
		int kir = rng()%n;
		vector<int> bits;
		for(int j = 0; j < m; j++) if((a[kir]>>j)&1) bits.push_back(j);
		memset(msk, 0, sizeof msk);
		for(int i = 0; i < n; i++) {
			int cur = 0;
			for(int j = 0; j < bits.size(); j++)
				cur |= ((a[i]>>bits[j])&1)<<j;
			msk[cur]++;
		}
		for(int j = 1; j < 1<<bits.size(); j*=2)
			for(int i = 0; i < 1<<bits.size(); i++)
				if(!(i&j))
					msk[i] += msk[i^j];
		for(int i = 0; i < 1<<bits.size(); i++) {
			if(msk[i] >= n-msk[i] && ans.first < cnt[i]) {
				ans.first = cnt[i];
				ans.second = 0;
				for(int j = 0; j < bits.size(); j++) if((i>>j)&1)
					ans.second |= 1ll<<bits[j];
			}
		}
	}
	for(int i = 0; i < m; i++)
		cout << ((ans.second>>i)&1);
}