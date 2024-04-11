// Problem: F. Let's Play the Hat?
// Contest: Codeforces - Codeforces Round #762 (Div. 3)
// URL: https://codeforces.com/contest/1619/problem/F
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
		int n, m, k;
		cin >> n >> m >> k;
		int big = n%m;
		vector<int> b(n);
		priority_queue<array<int, 2>> pq;
		for(int i = 0; i < n; i++)
			pq.push({0, i});
		for(int g = 0; g < k; g++) {
			for(int i = 0; i < big; i++) {
				cout << (n/m)+1 << " ";
				for(int j = 0; j < (n/m)+1; j++) {
					auto [v, id] = pq.top();
					cout << 1+id << " ";
					pq.pop();
					b[id]++;
				}
				cout << '\n';
			}
			for(int i = 0; i < m-big; i++) {
				cout << (n/m) << " ";
				for(int j = 0; j < (n/m); j++) {
					auto [v, id] = pq.top();
					cout << 1+id << " ";
					pq.pop();
				}
				cout << '\n';
			}
			assert(pq.empty());
			for(int i = 0; i < n; i++)
				pq.push({-b[i], i});
		}
		assert(*min_element(all(b))-*max_element(all(b))>=-1);
	});
	
}