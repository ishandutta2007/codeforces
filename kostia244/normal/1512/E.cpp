// Problem: E. Permutation by Sum
// Contest: Codeforces - Codeforces Round #713 (Div. 3)
// URL: https://codeforces.com/contest/1512/problem/E
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
		int n, l, r, s;
		cin >> n >> l >> r >> s;
		vector<int> vals(r-l+1);
		iota(all(vals), 1);
		ll sum = 0;
		for(auto i : vals) sum += i;
		int p = vals.size()-1, cap = n;
		while(p >= 0 && sum < s) {
			if(vals[p] == cap) {
				cap--;
				p--;
			} else {
				vals[p]++;
				sum++;
			}
		}
		if(sum != s) {cout << "-1\n"; return;}
		set<int> vv;
		for(int i = 1; i <= n; i++) vv.insert(i);
		for(auto i : vals) vv.erase(i);
		while(--l) {
			cout << *vv.begin() << " ";
			vv.erase(vv.begin());
		}
		for(auto i : vals)
			cout << i << " ";
		r = n-r;
		while(r--) {
			cout << *vv.begin() << " ";
			vv.erase(vv.begin());
		}
		cout << '\n';
	});
	
}