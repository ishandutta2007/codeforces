// Problem: A. Circle Coloring
// Contest: Codeforces - Grakn Forces 2020
// URL: https://codeforces.com/contest/1408/problem/A
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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n;
		cin >> n;
		vector<vector<int>> a(3, vector<int>(n));
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < n; j++)
				cin >> a[i][j];
		for(int fi = -1, lst = -1, i = 0; i < n; i++) {
			if(i == n-1) {
				int x = 0;
				while(a[x][i] == lst || a[x][i] == fi)
					x++;
				cout << (lst=a[x][i]) << " ";
			} else {
				int x = 0;
				while(a[x][i] == lst)
					x++;
				cout << (lst=a[x][i]) << " ";
				if(i == 0) fi = lst;
			}
		}
		cout << '\n';
	});
	
}