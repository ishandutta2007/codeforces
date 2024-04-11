// Problem: B. William the Vigilant
// Contest: Codeforces - Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1609/problem/B
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
	//multitest([&](){});
	string s;
	int n, q;
	cin >> n >> q >> s;
	int p;
	char c;
	auto get = [&](int i) ->int {
		if(i+2 >= n || i < 0) return 0;
		return s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c';
	};
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans += get(i);
	while(q--) {
		cin >> p >> c;
		for(int i = p-4; i < p+4; i++)
			ans -= get(i);
		s[p-1] = c;
		for(int i = p-4; i < p+4; i++)
			ans += get(i);
		cout << ans << '\n';
	}
}