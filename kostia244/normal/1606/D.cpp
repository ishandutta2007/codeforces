// Problem: D. Red-Blue Matrix
// Contest: Codeforces - Educational Codeforces Round 116 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1606/problem/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
		vector<vector<int>> a(n, vector<int>(m));
		for(auto &i : a)
			for(auto &j : i) 
				cin >> j;
		auto Mp = a, mp = a;
		auto Ms = a, ms = a;
		for(int i = 0; i < n; i++) {
			for(int j = 1; j < m; j++)
				Mp[i][j] = max(Mp[i][j], Mp[i][j-1]);
			for(int j = 1; j < m; j++)
				mp[i][j] = min(mp[i][j], mp[i][j-1]);
			for(int j = m-2; j>=0; j--)
				Ms[i][j] = max(Ms[i][j], Ms[i][j+1]);
			for(int j = m-2; j>=0; j--)
				ms[i][j] = min(ms[i][j], ms[i][j+1]);
		}
		pair<string, int> ans = [&]() -> pair<string, int> {
			for(int j = 0; j+1 < m; j++) {
				multiset<int> a[4];
				vector<array<int, 5>> rows;
				for(int i = 0; i < n; i++) {
					rows.push_back({Mp[i][j], mp[i][j], Ms[i][j+1], ms[i][j+1], i});
					a[1].insert(mp[i][j]);
					a[2].insert(Ms[i][j+1]);
				}
				string cur(n, 'R');
				sort(all(rows));
				int it = n;
				for(auto [Mp, mp, Ms, ms, id] : rows) {
					if(--it == 0) break;
					cur[id] = 'B';
					a[1].erase(a[1].find(mp));
					a[2].erase(a[2].find(Ms));
					a[0].insert(Mp);
					a[3].insert(ms);
					if(*a[0].rbegin() < *a[1].begin() && *a[2].rbegin() < *a[3].begin())
						return {cur, j+1};
				}
			}
			return {"", -1};
		}();
		if(ans.first.size()) cout << "YES\n" << ans.first << " " << ans.second << '\n';
		else cout << "NO\n";
	});
	
}