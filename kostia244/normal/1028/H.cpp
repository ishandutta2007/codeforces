// Problem: H. Make Square
// Contest: Codeforces - AIM Tech Round 5 (rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1028/problem/H
// Memory Limit: 1024 MB
// Time Limit: 7000 ms
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
const int N = 6e6 + 16, C = 16;
int lp[N], sq[N], cnt[N][C];
vector<int> pr;
void sieve() {
	sq[1] = 1;
	for(int i = 2; i < N; i++) {
		if(lp[i] == 0)
			pr.push_back(lp[i] = i);
		sq[i] = sq[i/lp[i]];
		if(sq[i]%lp[i] == 0)
			sq[i] /= lp[i];
		else
			sq[i] *= lp[i];
		for(int j = 0; j < pr.size() && pr[j] <= lp[i] && pr[j]*i < N; j++)
			lp[pr[j]*i] = pr[j];
	}
}
void upd(int x, int v, int y = 1, int dep = 0) {
	if(x>1)
		upd(x/lp[x], v, y, dep+1), upd(x/lp[x], v, y*lp[x], dep);
	else {
		// cout << "U " << y << " " << dep << " " << d << endl;
		cnt[y][dep] = v;
	}
}
array<int, C> tmp;
void check(int x, int y = 1, int d = 0) {
	if(x>1)
		check(x/lp[x], y, d+1), check(x/lp[x], y*lp[x], d);
	else {
		for(int i = 0; i<C/2; i++)
			tmp[d+i] = max(tmp[d+i], cnt[y][i]);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	sieve();
	int n, q;
	cin >> n >> q;
	vector<array<int, C>> f(n);
	vector<int> a(n);
	memset(cnt, -1, sizeof cnt);
	for(auto &i : a) cin >> i, i = sq[i];
	for(int i = 0; i < n; i++) {//longest segment with answer >r
		tmp.fill(-1);
		check(a[i]);
		f[i] = tmp;
		upd(a[i], i);
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; i && j < C; j++)
			f[i][j] = max(f[i][j], f[i-1][j]);
		for(int j = 1; j < C; j++)
			f[i][j] = max(f[i][j], f[i][j-1]);
	}
	for(int l, r; q--;) {
		cin >> l >> r;l--,r--;
		int x = 0;
		while(f[r][x]<l)
			x++;
		cout << x << '\n';
	}
}