// Problem:  XOR- 
// Contest: Codeforces
// URL: https://m1.codeforces.com/contest/1654/problem/F
// Memory Limit: 512 MB
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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n;
	string s;
	cin >> n >> s;
	vector<int> rank(s.size());
	for(int i = 0; i < s.size(); i++)
		rank[i] = s[i]-'a';
	for(int b = 0; b < n; b++) {
		vector<array<int, 3>> ars;
		for(int i = 0; i < s.size(); i+=2<<b) {
			for(int j = 0; j < 1<<b; j++) {
				ars.push_back({rank[i+j], rank[i+j+(1<<b)], i+(j)});
				ars.push_back({rank[i+j+(1<<b)], rank[i+j], i+(j|(1<<b))});
			}
		}
		sort(all(ars));
		rank[ars[0][2]] = 0;
		// for(auto [a, b, c] : ars) cout << a << " " << b << " " << c << endl;
		for(int r = 0, j = 1; j < ars.size(); j++) {
			if(ars[j-1][0] != ars[j][0] || ars[j-1][1] != ars[j][1])
				r++;
			rank[ars[j][2]] = r;
		}
		// for(int i = 0; i < s.size(); i++) cout << rank[i] << " "; cout << endl;
	}
	int X = min_element(all(rank))-rank.begin();
	for(int i = 0; i < 1<<n; i++)
		cout << s[i^X]; cout << '\n';
}