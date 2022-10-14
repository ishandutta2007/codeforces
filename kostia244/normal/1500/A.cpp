// Problem: A. Going Home
// Contest: Codeforces - Codeforces Round #707 (Div. 1, based on Moscow Open Olympiad in Informatics)
// URL: https://codeforces.com/contest/1500/problem/A
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

const int maxa = 5e6 + 1000;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n;
	cin >> n;
	n = min(n, 10000);
	vector<array<int, 2>> a(n);
	int idx = 0;
	for(auto &i : a) cin >> i[0], i[1] = ++idx;
	sort(all(a));
	vector<array<int, 2>> fi(maxa, {-1, -1});
	vector<array<int, 2>> la(maxa, {-1, -1});
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			int f = (maxa/2) + a[i][0]-a[j][0];
			if(fi[f][1] == -1 || fi[f][1] > j) fi[f] = {i, j};
			la[f] = {i, j};
		}
	}
	for(int i = 0; i < maxa; i++) if(fi[i][0] != -1) {
		if(fi[i][1] < la[i][0]) {
			
			cout << "YES\n";
			cout << a[fi[i][0]][1] << " " << a[la[i][1]][1] << " " << a[la[i][0]][1] << " " << a[fi[i][1]][1] << endl;
			exit(0);
		}
	}
	cout << "NO\n";
}