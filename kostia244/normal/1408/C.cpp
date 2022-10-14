// Problem: C. Discrete Acceleration
// Contest: Codeforces - Grakn Forces 2020
// URL: https://codeforces.com/contest/1408/problem/C
// Memory Limit: 256 MB
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
using ld = long double;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout << fixed << setprecision(15);
	multitest([&](){
		int n, l;
		cin >> n >> l;
		vector<int> a(n);
		for(auto &i : a) 
			cin >> i;
		auto b = a;
		for(auto &i : b)
			i = l-i;
		reverse(all(b));
		a.push_back(l);
		b.push_back(l);
		auto calc = [](vector<int> a, ld t) -> ld {
			int s = 1, p = 0;
			for(int i = 0; i < a.size(); i++) {
				if((a[i]-p) <= s*t)
					t -= ld(a[i]-p)/s;
				else {
					return p + t*s;
				}
				p = a[i], s++;
			}
			return a.back();
		};
		ld lo = 0, r = 1e9;
		for(int it = 100; it--;) {
			ld m = (lo+r)/2;
			if(calc(a, m)+calc(b, m) >= l)
				r = m;
			else
				lo = m;
		}
		cout << r << '\n';
	});
}