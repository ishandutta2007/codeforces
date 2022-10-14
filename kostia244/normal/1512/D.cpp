// Problem: D. Corrupted Array
// Contest: Codeforces - Codeforces Round #713 (Div. 3)
// URL: https://codeforces.com/contest/1512/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n;cin >> n;
		vector<ll> a(n+2);
		ll s = 0;
		map<ll, ll> cnt;
		for(auto &i : a) cin >> i, cnt[i]++, s += i;
		for(auto &i : a) {
			cnt[i]--;
			if(cnt[s-2*i]) {
				cnt[s-2*i]--;
				for(auto [v, c] : cnt) {
					while(c-->0)
						cout << v << " ";
				}
					cout << '\n';
				return;
			}
			cnt[i]++;
		}
		cout << "-1\n";
	});
	
}