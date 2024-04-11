// Problem: C. Representative Edges
// Contest: Codeforces - Good Bye 2021: 2022 is NEAR
// URL: https://codeforces.com/contest/1616/problem/C
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
	multitest([&](){
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto &i : a) cin >> i;
		if(n < 3) {
			cout << "0\n";
			return;
		}
		int ans = n;
		for(int i = 0; i < a.size(); i++) {
			for(int j = i+1; j < a.size(); j++) if(i != j) {
				for(int d = j-i; d <= j-i; d++) {
					int cur = n;
					//a[i] = start, (a[j]-a[i])/d step
					for(int k = 0; k < n; k++) {
						int f = a[k];
						f -= a[i];
						f *= d;
						if(f == (a[j]-a[i])*(k-i))
							cur--;
					}
					ans = min(cur, ans);
				}
			}
		}
		cout << ans << '\n';
	});
	
}