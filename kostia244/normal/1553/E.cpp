// Problem: E.  
// Contest: Codeforces - Harbour.Space Scholarship Contest 2021-2022 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1553/problem/E
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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n, m;
		cin >> n >> m;
		vector<int> a(n), cnt(n);
		for(auto &i : a) cin >> i;
		for(int i = 0; i < n; i++) {
			cnt[(n+i-(a[i]-1))%n]++;
		}
		auto check = [](vector<int> p) {
			int n = p.size(), ans = n;
			vector<int> vis(n);
			for(int i = 0; i < n; i++) if(!vis[i]) {
				int t = i;
				while(!vis[t]) {
					vis[t]=1;
					t = p[t];
				}
				ans--;
			}
			return ans;
		};
		vector<int> ans;
		for(int i = 0; i < n; i++) if(cnt[i]*3 >= n) {
			vector<int> b(n);
			for(int j = 0; j < n; j++)
				b[j] = a[(j+i)%n]-1;
			if(check(b)<=m)
				ans.push_back(i);
		}
		cout << ans.size() << " ";for(auto i : ans) cout << i << " ";cout << '\n';
	});
	
}