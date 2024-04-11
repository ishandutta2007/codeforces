// Problem: E. Minimax
// Contest: Codeforces - Codeforces Round #733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine))
// URL: https://codeforces.com/contest/1530/problem/E
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
		string s;
		cin >> s;
		vector<int> cnt(256);
		for(auto &i : s) cnt[i]++;
		vector<char> hv;
		for(char c = 'a'; c <= 'z'; c++) {
			if(cnt[c] == 1) {
				sort(all(s));
				cout << c;
				for(auto i : s) if(i!=c) cout << i;
				cout << '\n';
				return;
			}
			if(cnt[c]) hv.push_back(c);
		}
		if(hv.size() == 1) {
			cout << s << '\n';
			return;
		}
		if(cnt[hv[0]]-2 > (s.size()-cnt[hv[0]])) {//Can't get AA
			if(hv.size() > 2) {
				cout << hv[0], cnt[hv[0]]--;
				cout << hv[1], cnt[hv[1]]--;
				while(cnt[hv[0]]-->0) cout << hv[0];
				cout << hv[2], cnt[hv[2]]--;
				for(auto i : hv)
					while(cnt[i]-->0) cout << i;
			} else {
				cout << hv[0];
				cnt[hv[0]] -= 1;
				while(cnt[hv[1]]--) cout << hv[1];
				for(auto c : hv) {
					while(cnt[c]-->0) cout << c;
				}
			}
		} else {
			string t;
			for(auto i : hv) if(i != hv[0]) {
				for(int j = cnt[i]; j--;)
					t += i;
			}
			reverse(all(t));
			cout << hv[0], cnt[hv[0]]--;
			while(cnt[hv[0]]--) {
				cout << hv[0];
				if(t.size()) 
				cout << t.back(), t.pop_back();
			}
			while(t.size()) cout << t.back(), t.pop_back();
		}
		cout << '\n';
	
	});
	
}