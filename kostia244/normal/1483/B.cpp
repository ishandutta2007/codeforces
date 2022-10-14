// Problem: B. Playlist
// Contest: Codeforces - Codeforces Round #709 (Div. 1, based on Technocup 2021 Final Round)
// URL: https://codeforces.com/contest/1483/problem/B
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
#define N(x) (((x)+1)%n)
int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n;cin >> n;
		vector<deque<array<int, 2>>> a;
		for(int t, i = 0; i < n; i++) {
			cin >> t;
			a.push_back(deque<array<int, 2>>{{t, i}});
		}
		auto merge = [&](deque<array<int, 2>> &a, deque<array<int, 2>> &b) {
			if(a.size() < b.size()) {
				for(int i = a.size(); i--;)
					b.push_front(a[i]);
				swap(a, b);
			} else {
				for(int i = 0; i< b.size(); i++)
					a.push_back(b[i]);
			}
		};
		auto fold = [&](vector<deque<array<int, 2>>> &a) {
			vector<deque<array<int, 2>>> b;
			for(int i = 0; i < a.size(); i++) if(!a[i].empty()) {
				if(b.size() && __gcd(b.back().back()[0], a[i][0][0]) > 1)
					merge(b.back(), a[i]);
				else {
					b.push_back({});
					swap(b.back(), a[i]);
				}
			}
    		swap(a, b);
		};
		fold(a);
		vector<int> rem;
		while(true) {
			if(a.size() == 1 && a[0].empty()) break;
			for(int i = 1; i < a.size(); i++) {
				if(a[i-1].size() && a[i].size()) {
					rem.push_back(a[i].front()[1]);
					a[i].pop_front();
				}
			}
			if(a.size() == 1) {
				if(__gcd(a[0][0][0], a[0].back()[0]) > 1) break;
				rem.push_back(a[0].front()[1]);
				a[0].pop_front();
			} else if(a.back().size()) {//didn't remove last
				fold(a);
				if(__gcd(a[0][0][0], a.back().back()[0]) == 1) {
					rem.push_back(a[0].front()[1]);
					a[0].pop_front();
				}
			} else
				fold(a);
		}
		cout << rem.size() << " ";
		for(auto i : rem) cout << 1+i << " "; cout << '\n';
	});
	
}