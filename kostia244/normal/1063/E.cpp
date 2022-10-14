// Problem: E. Lasers and Mirrors
// Contest: Codeforces - Codeforces Round #516 (Div. 1, by Moscow Team Olympiad)
// URL: https://codeforces.com/contest/1063/problem/E
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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n;
	cin >> n;
	vector<int> a(n); 
	for(auto &i : a) cin >> i, i--;
	int triv = 1;
	for(int i = 0; i < n; i++)
		triv &= a[i] == i;
	if(triv) {
		cout << n << '\n';
		for(int i = 0; i < n; i++)
			cout << string(n, '.') << '\n';
		return 0;
	}
	vector<string> sol;
	a[0] = -1;
	for(int L = 0, R = n-1, i = 0; i < n; i++) {
		string s(n, '.');
		while(L < R && a[L] == L) L++;
		while(L < R && a[R] == R) R--;
		if(L == R) break;
		if(i%2 == 0) {
			int j = R;
			while(j > L && a[j] == j)
				j--;
			int k = a[j];
			assert(k < j);
			s[L] = s[j] = s[k] = s[R] = '\\';
			a[L] = a[k], a[k] = a[j], a[j] = a[R], a[R] = -1;
		} else {
			int j = L;
			while(j < R && a[j] == j)
				j++;
			int k = a[j];
			assert(k > j);
			s[L] = s[j] = s[k] = s[R] = '/';
			a[R] = a[k], a[k] = a[j], a[j] = a[L], a[L] = -1;
		}
		sol.push_back(s);
	}
	while(sol.size() < n) sol.push_back(string(n, '.'));
	reverse(all(sol));
	cout << n-1 << '\n';
	for(auto i : sol) cout << i << '\n';
}