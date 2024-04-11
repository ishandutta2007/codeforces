// Problem: E. The Cells on the Paper
// Contest: Codeforces - Codeforces Round #758 (Div.1 + Div. 2)
// URL: https://codeforces.com/contest/1608/problem/E
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
template<class T>
struct fenwick {
	int sz;
	vector<T> tr;

	fenwick(int n = 0) {
		sz = n+1;
		tr.resize(n+2);
	}

	T query(int idx) {
		T ans = 0;
		for(; idx >= 1; idx -= (idx & -idx)) {
			ans += tr[idx];
		}

		return ans;
	}

	void update(int idx, T val) {
		if(idx <= 0) return;
		for(; idx <= sz; idx += (idx & -idx)) {
			tr[idx] += val;	
		}
	}

	T query(int l, int r) { 
		return query(r) - query(l - 1); 
	}
};

struct Rect {
	fenwick<int> cf[3];
	int n;
	Rect(int n) : n(n) {
		for(int i = 0; i < 3; i++)
			cf[i] = fenwick<int>(n);
	}
	void add_point(int x, int c) {
		cf[c].update(x, 1);
	}
	int best(int x, int y) {
		int tot = cf[y].query(n), p = 0;
		int cx = 0, cy = 0;
		for(int z = 1<<20; z>>=1;) if((p|z) <= n) {
			int tx = cx + cf[x].tr[p|z];
			int ty = cy + cf[y].tr[p|z];
			if(tx <= tot-ty) {
				p |= z;
				cx = tx;
				cy = ty;
			}
		}
		auto get = [&](int i) {
			i = min(i, n);
			return min(cf[x].query(i), tot-cf[y].query(i));
		};
		return max(get(p), get(p+1));
	}
	array<int, 3> best() {
		array<int, 3> ans;
		ans[0] = max(best(1, 2), best(2, 1));
		ans[1] = max(best(0, 2), best(2, 0));
		ans[2] = max(best(0, 1), best(1, 0));
		return ans;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n;
	cin >> n;
	vector<array<int, 3>> a(n);
	vector<int> X, Y;
	for(auto &[x, y, z] : a) {
		cin >> x >> y >> z;
		z--;
		X.push_back(x);
		Y.push_back(y);
	}
	sort(all(X));
	X.erase(unique(all(X)), X.end());
	sort(all(Y));
	Y.erase(unique(all(Y)), Y.end());
	for(auto &[x, y, z] : a) {
		x = lower_bound(all(X), x)-X.begin()+1;
		y = lower_bound(all(Y), y)-Y.begin()+1;
	}
	auto solve = [&]() {
		int ans = 0;
		map<int, vector<array<int, 2>>> pts;
		array<int, 3> cnt {0, 0, 0};
		for(auto [x, y, z] : a) {
			pts[x].push_back({y, z});
			cnt[z]++;
		}
		Rect rx(n), ry(n);
		for(auto &[x, vec] : pts) {
			for(auto [y, z] : vec) {
				rx.add_point(x, z);
				ry.add_point(y, z);
				cnt[z]--;
			}
			auto A = rx.best(), B = ry.best();
			for(int i = 0; i < 3; i++) {
				ans = max(ans, min(cnt[i], max(A[i], B[i])));
			}
		}
		return ans;
	};
	int ans = 0;
	ans = max(ans, solve());
	for(auto &[x, y, z] : a)
		x *= -1;
	ans = max(ans, solve());
	for(auto &[x, y, z] : a)
		x *= -1, swap(x, y);
	ans = max(ans, solve());
	for(auto &[x, y, z] : a)
		x *= -1;
	ans = max(ans, solve());
	cout << ans*3 << '\n';
}