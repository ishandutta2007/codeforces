// Problem: A. Diamond Miner
// Contest: Codeforces - Codeforces Round #706 (Div. 1)
// URL: https://codeforces.com/contest/1495/problem/A
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
using ld = long double;

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
		vector<ll> a, b;
		for(ll x, y, i = 0; i < 2*n; i++) {
			cin >> x >> y;
			if(x == 0) a.push_back(y*y);
			else b.push_back(x*x);
		}
		sort(all(a)), sort(all(b));
		ld ans = 0;
		for(int i = 0; i < n; i++) ans += sqrt(a[i]+b[i]);//, cout << a[i] << " " << b[i] << " " << sqrt(a[i]*a[i]+b[i]*b[i]) << endl;
		cout << fixed << setprecision(15) << ans << '\n';
	});return 0;
	for(int a = 1; a <= 300; a++)
		for(int b = a; b <= 300; b++)
			for(int c = 1; c <= 300; c++)
				for(int d = c; d <= 300; d++) {
					ld x = sqrt(a*a+c*c) + sqrt(b*b+d*d);
					ld y = sqrt(a*a+d*d) + sqrt(b*b+c*c);
					assert(x <= y);
				}
				
}