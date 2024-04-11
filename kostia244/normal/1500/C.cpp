// Problem: C. Matrix Sorting
// Contest: Codeforces - Codeforces Round #707 (Div. 1, based on Moscow Open Olympiad in Informatics)
// URL: https://codeforces.com/contest/1500/problem/C
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

void gg() {
	cout << "-1\n";
	exit(0);
}
int n, m;
vector<vector<int>> a, b, c;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n >> m;
	a = b = c = vector<vector<int>>(n, vector<int>(m));
	for(auto &i : a)
		for(auto &j : i)
			cin >> j;
	for(auto &i : b)
		for(auto &j : i)
			cin >> j;
	c = a;
	sort(all(c));
	vector<int> cid(n, -1), bid(n);
	for(int i = 0; i < n; i++) {
		int pos = lower_bound(all(c), a[i])-c.begin();
		if(cid[pos] == -1) cid[pos] = i;
	}
	for(int i = 0; i < n; i++) {
		int pos = lower_bound(all(c), b[i])-c.begin();
		if(pos >= c.size() || c[pos] != b[i]) gg();
		bid[i] = cid[pos]++;
	}
	vector<int> cuts(n), a_sad(m);
	int ord_sad = 0;
	for(int i = 1; i < n; i++) {
		ord_sad += bid[i-1] > bid[i];
		for(int j = 0; j < m; j++) {
			a_sad[j] += b[i-1][j] > b[i][j];
		}
	}
	vector<int> ans, used(m);
	auto make_cut = [&](int pos) {
		if(cuts[pos]) return;//i | i+1
		cuts[pos] = 1;
		ord_sad -= bid[pos] > bid[pos+1];
		for(int j = 0; j < m; j++)
			a_sad[j] -= b[pos][j] > b[pos+1][j];
	};
	auto make_sort = [&](int pos) {
		ans.push_back(pos);
		used[pos] = 1;
		for(int i = 0; i+1 < n; i++) {
			if(b[i][pos] != b[i+1][pos]) make_cut(i);
		}
	};
	while(true) {
		int x = 0;
		for(; x < m && (used[x] || a_sad[x]); x++);
		if(x == m) break;
		make_sort(x);
	}
	if(ord_sad) gg();
	cout << ans.size() << '\n';
	reverse(all(ans));
	for(auto &i : ans)  cout << 1+i << " "; cout << endl;
}