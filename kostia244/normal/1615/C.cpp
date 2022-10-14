// Problem: C. 
// Contest: Codeforces - Codeforces Global Round 18
// URL: https://codeforces.com/contest/1615/problem/C
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
		string s, t;
		int n;
		cin >> n >> s >> t;
		int c1 = count(all(s), '1'), c2 = count(all(t), '1');
		int ans = 1<<30;
		int x = 0, y = 0;
		for(int i = 0; i < n; i++) {
			if(s[i] == t[i]) x++;
			else y++;
		}
		if(c1 == c2)
			ans = y;
		int nc1 = 1+(n-c1);
		if(nc1 == c2) {
			for(int i = 0; i < n; i++) if(s[i] == '1') {
				int a = x, b = y;
				if(s[i] == t[i]) a--;
				else b--;
				swap(a, b);
				if(s[i] == t[i]) a++;
				else b++;
				ans = min(ans, 1+b);
			}
		}
		if(ans == 1<<30) ans = -1;
		cout << ans << '\n';
	});
	
}