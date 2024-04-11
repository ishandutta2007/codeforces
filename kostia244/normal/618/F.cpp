// Problem: F.  
// Contest: Codeforces - Wunder Fund Round 2016 (Div. 1 + Div. 2 combined)
// URL: https://codeforces.com/contest/618/problem/F
// Memory Limit: 256 MB
// Time Limit: 2500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

void answer(vector<int> a) {
	vector<int> U, V;
	for(auto &i : a) {
		if (i >= 0) {
			U.push_back(i);
		} else {
			V.push_back(-i-1);
		}
	}
	cout << U.size() << '\n';
	for(auto i : U) cout << 1+i << " "; 
	cout << '\n';
	cout << V.size() << '\n';
	for(auto i : V) cout << 1+i << " "; 
	cout << '\n';
	exit(0);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(auto &i : a) cin >> i;
	for(auto &i : b) cin >> i;
	vector<int> A(n), B(n);
	iota(all(A), 0); iota(all(B), 0);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	for(int iter = 0; iter < 5; iter++) {
		shuffle(all(A), rng);
		shuffle(all(B), rng);
		vector<int> ord;
		ord.reserve(2*n);
		vector<int> have(2*n+1, -1);
		have[n] = 0;
		ll sum = 0;
		int i = 0, j = 0;
		while(i < n && j < n) {
			if(sum <= 0) {
				sum += a[A[i]];
				ord.push_back(A[i++]);
			} else {
				sum -= b[B[j]];
				ord.push_back(-B[j++]-1);
			}
			if (have[n + sum] != -1)
				answer(vector<int>{ord.begin() + have[n + sum], ord.end()});
			have[n + sum] = i + j;
		}
	}
	cout << "-1\n";
}