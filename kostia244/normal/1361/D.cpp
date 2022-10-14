// Problem: D.   
// Contest: Codeforces - Codeforces Round #647 (Div. 1) - Thanks, Algo Muse!
// URL: https://codeforces.com/contest/1361/problem/D
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
using ld = long double;
array<int, 2> L(int x, int y) {//diff sign intended
	int g = __gcd(abs(x), abs(y));
	return {x/g, y/g};
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n, k;
	cin >> n >> k;
	map<array<int, 2>, vector<ld>> lines_;
	for(int x, y, i = 0; i < n; i++) {
		cin >> x >> y;
		if(x||y)
			lines_[L(x, y)].push_back(sqrt(x*1ll*x+y*1ll*y));
	}
	vector<vector<ld>> lines;
	for(auto [_, l] : lines_) {
		lines.push_back(l);
		sort(all(lines.back()));
	}
	auto solve = [&](int k, int f) -> ld {
		if(k > n-1) return 0;
		vector<pair<ld, int>> A;
		for(int i = 0; i < lines.size(); i++) {
			reverse(all(lines[i]));
			for(int j = 0; j < lines[i].size(); j++) {
				A.push_back({lines[i][j]*(k-2*j-f), i});
			}
			reverse(all(lines[i]));
		}
		sort(all(A), greater<>());
		ld ans = 0;
		for(int i = 0; i < k; i++) 
			ans += A[i].first;
		for(int i = 0; i < lines.size(); i++) if(lines[i].size() >= (k/2)-2) {
			ld sm = 0, cur = 0;
			vector<ld> other(k+1, 0);
			for(int j = 0, x = 0; x < A.size() && j < k; x++) {
				if(A[x].second != i)
					sm += A[x].first, j++;
				other[j] = sm;
			}
			auto pref = lines[i];
			for(int j = 1; j < pref.size(); j++)
				pref[j] += pref[j-1];
			for(int gg = 0, p = 0, j = 1; j <= min((int)lines[i].size(), k); j++) {
				if(k-2*(j-1)-f >= 0) {
					cur += lines[i][lines[i].size()-j]*(k-2*(j-1)-f);
					gg = j+1;
				} else {
					if(p)
						cur += pref[p-1]*(-2);
					cur += lines[i][p++]*(k-2*(gg-1)-f);
				}
				if(n-1-lines[i].size() >= k-j) {
					ans = max(ans, cur + other[k-j]);
				}
			}
		}
		return ans;
	};
	cout << fixed << setprecision(10);
	cout << max(solve(k, 1), solve(k-1, 0)) << '\n';
}