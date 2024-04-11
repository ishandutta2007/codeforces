// Problem: C. Maximize the Intersections
// Contest: Codeforces - Codeforces Global Round 15
// URL: https://codeforces.com/contest/1552/problem/C
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
template<typename T>
struct fenwick
{
	int n;
	vector<T> f;
	fenwick(int n) : n(n), f(n + 1) {}
 
	T query(int p)
	{
		T ret = 0;
		for (++p; p > 0; p -= p & -p)
			ret += f[p];
		return ret;
	}
 
	void update(int p, T x)
	{
		for (++p; p <= n; p += p & -p)
			f[p] += x;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n, k;
		cin >> n >> k;
		vector<int> used(2*n+2);
		vector<array<int, 2>> pr(k);
		for(auto &[u, v] : pr) {
			cin >> u >> v;
			used[u] = used[v] = 1;
		}
		vector<int> fr;
		for(int i = 1; i <= 2*n; i++)
			if(!used[i]) fr.push_back(i);
		for(int t = fr.size()/2, i = 0; i+t < fr.size(); i++)
			pr.push_back({fr[i], fr[i+t]});
		for(auto &[i, v] : pr) {
			if(i > v) swap(i, v);
		}
		sort(all(pr));
		for(auto &[i, v] : pr) {
			//cout << i << " " << v << endl;
		}
		fenwick<int> ass(2*n+69);
		ll ans = 0, cnt = 0;
		for(auto [i, v] : pr) {
			ans += ass.query(v)-ass.query(i-1);
			//cout << ans << "_"<<endl;
			ass.update(v, 1);
			cnt++;
		}
		cout << ans << '\n';
	});
	
}