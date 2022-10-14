// Problem: C. Challenging Cliffs
// Contest: Codeforces - Codeforces Round #726 (Div. 2)
// URL: https://codeforces.com/contest/1537/problem/C
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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n;
		cin>> n;
		vector<int> a(n);
		for(auto &i : a) cin >> i;
		sort(all(a));
		array<int, 3> res = {-1239129213, -112, 0};
		for(int j = 1; j < n; j++)
			res = max(res, array<int, 3>{a[j-1]-a[j], j==1||j==n-1, j});
		//1 2 .. n
		//1 ... n 2
		//n 1 .... n-1
		//x+1 .. n 1 2 .. x-1 x
		swap(a[res[2]], a[res[2]-1]);
		for(int i = res[2]; i < n; i++) cout << a[i] << " ";
		for(int i = 0; i < res[2]; i++) cout << a[i] << " ";
		cout << '\n';
	});
	
}