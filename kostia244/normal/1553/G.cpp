// Problem: G.   
// Contest: Codeforces - Harbour.Space Scholarship Contest 2021-2022 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1553/problem/G
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
const int N = 1006969;
vector<int> lp(N+1);
vector<int> pr;
struct dsu {
	vector<int> e;
	dsu(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};
vector<int> reach[N+1];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	for (int i=2; i <= N; ++i) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.push_back(i);
	    }
	    for (int j=0; j < (int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= N; ++j) {
	        lp[i * pr[j]] = pr[j];
	    }
	}
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(auto &i : a) cin >> i;
	dsu d(N+1);
	for(int i = 0; i < n; i++) {
		int t = a[i];
		while(t > 1) {
			d.join(a[i], lp[t]);
			t /= lp[t];
		}
	}
	for(int i = 0; i < n; i++) {
		int t = a[i]+1;
		vector<int> b;
		while(t > 1) {
			b.push_back(d.find(lp[t]));
			t /= lp[t];
		}
		sort(all(b));
		b.erase(unique(all(b)), b.end());
		for(auto x : b)
			reach[d.find(a[i])].push_back(x);
		for(int i = 0; i < b.size(); i++)
			for(int j = 0; j < i; j++) {
				reach[b[i]].push_back(b[j]);
			}
	}
	for(int i = 0; i < N; i++)
		sort(all(reach[i]));
	for(int x, y; q--;) {
		cin >> x >> y;x = a[x-1], y = a[y-1];
		x = d.find(x), y = d.find(y);
		if(x == y) {
			cout << "0\n";
		} else {
			int t = binary_search(all(reach[x]), y)||binary_search(all(reach[y]), x);
			cout << 2-t << '\n';
		}
	}
}