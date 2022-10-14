// Problem: C. Hidden Permutations
// Contest: Codeforces - Hello 2022
// URL: https://codeforces.com/contest/1621/problem/C
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
		vector<int> _q = {0, 1, 2, 3, 4}, p = {0, 2, 1, 4, 3};
		auto ask = [&](int x) {
			cout << "? " << x << endl;
			cin>> x;
			return x;
		};
		vector<int> vis(n+1), ans(n+1);
		for(int i = 1; i <= n; i++) if(!vis[i]) {
			vector<int> cyc;
			int t = i;
			while(true) {
				t = ask(i);
				if(vis[t]++)
					break;
				cyc.push_back(t);
			}
			for(int i = 0; i < cyc.size(); i++)
				ans[cyc[i]] = cyc[(i+1)%cyc.size()];
		}
		cout << "! "; for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
	});
}