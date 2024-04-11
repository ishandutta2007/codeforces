// Problem: F.   
// Contest: Codeforces - Codeforces Round #816 (Div. 2)
// URL: https://codeforces.com/contest/1715/problem/F
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
using ld = long double;
ld ask(vector<array<ld, 2>> pts) {
	cout << "? " << pts.size() << '\n';
	for(auto [x, y] : pts) {
		cout << x << " " << y << '\n';
	}
	cout << endl;
	ld t;cin >> t;return t;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout << fixed << setprecision(15);
	int n, m;
	cin >> n >> m;
	vector<array<ld, 2>> pts {{n, -1}, {0, -1}};
	for(int i = 0; i < n; i+=2) {
		pts.push_back(array<ld, 2>{i, 0});
		pts.push_back(array<ld, 2>{i, m});
		pts.push_back(array<ld, 2>{i+1, m});
		pts.push_back(array<ld, 2>{i+1, 0});
	}
	ld x_a = ask(pts);
	pts = {{n, -1}, {0, -1}, {0, 0}};
	for(int i = 0; i+1 < n; i+=4) {
		pts.push_back(array<ld, 2>{i, 0});
		pts.push_back(array<ld, 2>{i, m});
		pts.push_back(array<ld, 2>{i+2, m});
		pts.push_back(array<ld, 2>{i+2, 0});
	}
	ld x_2 = ask(pts);
	if(abs(max(x_2, 1.-x_2)) > 1 - 1e-14) {
		x_a = 1. - x_a;
	}
	pts = {{n, -1}, {0, -1}, {0, 0}};
	for(int i = 0; i < n; i+=1) {
		pts.push_back(array<ld, 2>{x_a + i, 0});
		pts.push_back(array<ld, 2>{x_a + i, m});
		pts.push_back(array<ld, 2>{x_a + i+1, 0});
	}
	//A = (2k-1)/2m
	ld y = m - (ask(pts) * 2*m + 1)/2;
	pts = {{0, y}, {n, y}, {0, y+1}};
	ld x = n - (ask(pts) * 2*n + 1)/2;
	cout << "! " << x << " " << y << endl;
}