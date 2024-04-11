// Problem: A. Basic Diplomacy
// Contest: Codeforces - Codeforces Round #709 (Div. 1, based on Technocup 2021 Final Round)
// URL: https://codeforces.com/contest/1483/problem/A
// Memory Limit: 512 MB
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
		int n, m;
		cin >> n >> m;
		vector<vector<int>> days(m);
		vector<int> cnt(n), ans;
		for(auto &i : days) {
			int t;cin >> t;
			i.resize(t);
			for(auto &j : i) cin >> j, j--;
			if(t == 1) cnt[i[0]]++;
		}
		for(auto &i : days) {
			array<int, 2> use = {cnt[i[0]], i[0]};
			for(auto j : i)
				use = min(use, {cnt[j], j});
			ans.push_back(use[1]+1);
			if(i.size()>1)
				cnt[use[1]]++;
		}
		if(*max_element(all(cnt)) > (m+1)/2) {
			cout << "NO\n";
		} else {cout << "YES\n";
			for(auto i : ans) cout << i << " "; cout << endl;
		}
	});
	
}