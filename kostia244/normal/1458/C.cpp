// Problem: C. Latin Square
// Contest: Codeforces - Codeforces Round #691 (Div. 1)
// URL: https://codeforces.com/contest/1458/problem/C
// Memory Limit: 512 MB
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
const int N = 1010;
#define count loli
int count = 0;
int a[N][N];
void rec(int i, int n) {
	vector<int> cnt(n);
	int req = 1, ok = 1;
	for(int x = 0; ok && x < n; x++, req++)
		for(int j = 0; ok && j < i; j++) {
				ok &= cnt[a[j][x]] != req;
				cnt[a[j][x]] = req;
			}
	if(!ok) return;
	if(i==n) {count++;
		for(int i = 0; i < n; i++, cout << '\n')
			for(int j = 0; j < n; j++)
				cout << a[i][j] << " ";
		cout << '\n';
		return;
	}
	
	for(int x = 0; x < n; x++)
		a[i][x] = x;
	do {
		rec(i+1, n);
		if(!i) return;
	} while(next_permutation(a[i], a[i]+n));
}
void brute(int n) {
	count = 0;
	rec(0, n);
	cout << count << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n, m;
		string s;
		cin >> n >> m;
		vector<array<int, 3>> cur;
		cur.reserve(n*n);
		for(int i = 0; i < n; i++)
			for(int t, j = 0; j < n; j++)
				cin >> t, cur.push_back({i, j, t-1});
		cin >> s;
		array<int, 3> add = {0, 0, 0};
		array<int, 3> perm = {0, 1, 2};
		for(auto i : s) {
		//cout << i << ":\n";
			if(i == 'L')
				add[1]--;
			if(i == 'R')
				add[1]++;
			if(i == 'U')
				add[0]--;
			if(i == 'D')
				add[0]++;
			if(i == 'I') {
				swap(perm[1], perm[2]);
				swap(add[1], add[2]);
			}
			if(i == 'C') {
				swap(perm[0], perm[2]);
				swap(add[0], add[2]);
			}
		}
		for(auto &t : cur) {
			array<int, 3> z;
			for(int i = 0; i < 3; i++) {
				z[i] = t[perm[i]];
				z[i] += add[i];
				z[i] = (z[i]%n + n)%n;
			}
			t = z;
		}
		vector<vector<int>> a(n, vector<int>(n));
		for(auto &t : cur)
			a[t[0]][t[1]] = t[2]+1;
		for(auto i : a) {
			for(auto j : i)
				cout << j << " ";
			cout << '\n';
		}
		perm = {0, 1, 2}, add = {0, 0, 0};
		cout << '\n';
	});
}
/*
1
2
12
576
161280
*/