// Problem: E. Lexicographically Small Enough
// Contest: Codeforces - Good Bye 2021: 2022 is NEAR
// URL: https://codeforces.com/contest/1616/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
template <class T> struct fenwick {
	int sz;
	vector<int> tr;

	void init(int n) {
		sz = n + 1;
		tr = vector<T>(sz+1);
	}

	T query(int idx) {
		T ans = 0;
		for(; idx >= 1; idx -= (idx & -idx)) {
			ans += tr[idx];
		}

		return ans;
	}

	void update(int idx, T val) {
		if(idx <= 0) return;
		for(; idx <= sz; idx += (idx & -idx)) {
			tr[idx] += val;	
		}
	}

	T query(int l, int r) { 
		return query(r) - query(l - 1); 
	}
};
const int N = 1<<17;
vector<int> nxt[26];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n;
		string s, t;
		cin >> n >> s >> t;
		for(int i = 0; i < 26; i++)
			nxt[i].clear();
		for(int i = 0; i < n; i++)
			nxt[s[i]-'a'].push_back(i);
		for(int i = 0; i < 26; i++)
			reverse(all(nxt[i]));
		fenwick<int> f;
		f.init(n+3);
		for(int i = 1; i <= n; i++)
			f.update(i, 1);
		auto find = [&](int c) {
			int ans = 1<<30;
			for(int i =0 ;i <= c; i++) {
				if(!nxt[i].empty())
					ans = min(ans, nxt[i].back());
			}
			return ans;
		};
		auto pop = [&](int c) {
			f.update(c+1, -1);
			for(int i =0 ;i < 26; i++) {
				if(!nxt[i].empty() && nxt[i].back() == c)
					nxt[i].pop_back();
			}
		};
		auto real = [&](int x, int _) {
			return _ + f.query(1, x+1) - 1;
		};
		ll ans = 1ll<<60;
		ll base = 0;
		for(int i = 0; i < n; i++) {
			int nx = find(t[i]-'a'-1);
			if(nx != 1<<30) {
				ans = min(ans, base + real(nx, i)-i);
			}
			nx = find(t[i]-'a');
			if(nx == 1<<30)
				break;
			base += real(nx, i)-i;
			pop(nx);
		}
		if(ans == 1ll<<60) ans = -1;
		cout << ans << '\n';
	});
	
}