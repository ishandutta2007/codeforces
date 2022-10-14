// Problem: A. MEX-
// Contest: Codeforces - Codeforces Round #767 (Div. 1)
// URL: https://codeforces.com/contest/1628/problem/A
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
		int n;
		cin >> n;
		vector<int> cnt(n+3),a(n),b;
		for(auto &i : a) cin >> i, cnt[i]++;
		int i = 0;
		while(i < n) {
			int me = 0;
			while(cnt[me]) me++;
			vector<int> ccnt(me+2);
			b.push_back(me);
			int bad = me;
			int j = i;
			while(j < n && bad) {
				if(a[j] < me && ++ccnt[a[j]] == 1)
					bad--;
				j++;
			}
			j = max(j, i+1);
			while(i < j) cnt[a[i++]]--;
		}
		cout << b.size() << '\n';
		for(auto i : b) cout << i << " "; cout << '\n';
	});
	
}