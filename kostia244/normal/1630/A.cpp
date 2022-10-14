// Problem: A. And Matching
// Contest: Codeforces - Codeforces Round #768 (Div. 1)
// URL: https://codeforces.com/contest/1630/problem/A
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
void print(int n, int k) {
	
		int U = n-1;
		vector<int> use(n);
		if(k==U) {
			if(n<8)
				cout << "-1\n";
			else {
				vector<int> A, B;
				int L = __builtin_popcount(n-1);
				for(int i = 1; i < n; i++) {
					if(__builtin_popcount(i) == 1) A.push_back(i);
					if(__builtin_popcount(i)+1 == L) B.push_back(i);
					if(A.size())
					use[A.back()] =1;
					if(B.size())
					use[B.back()] = 1;
				}
				reverse(all(B));
				for(int i = 1; i < A.size(); i++) swap(A[i], A[i-1]);
				int ans = 0;
				for(int i = 0; i < A.size(); i++) cout << A[i] << " " << B[i] << '\n', ans += (A[i]&B[i]);
				for(int i = 0; i < n; i++) {
					if(__builtin_popcount(i) != 1 &&__builtin_popcount(i)+1 != L)
					if(i < (U^i)) {
						cout << i << " " << (U^i) << '\n';
				assert(++use[i] < 2);
				assert(++use[U^i] < 2);}
				}
				// cout << ans << endl;
				assert(ans==k);
				for(auto i : use) assert(i==1);
			}
			return;
		}
		if(k==0) cout << "0 " << U << '\n', use[0]=use[U] = 1;
		for(int i = 1; i+1 < n; i++) {
			if(i != k && (U^i) != k) {
				if(i < (U^i)) {
				cout << i << " " << (U^i) << '\n';
				assert(++use[i] < 2);
				assert(++use[U^i] < 2);}
			} else if(i == k) {
				cout << i << " " << U << '\n';
				assert(++use[i] < 2);
				assert(++use[U] < 2);
			} else {
				cout << i << " 0\n";
				assert(++use[i] < 2);
				assert(++use[0] < 2);
			}
		}
		for(auto i : use) assert(i==1);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	// for(int z = 0; z < 256; z++) print(256, z);
	multitest([&](){
		int n, k;
		cin >> n >> k;
		print(n, k);
	});
	
}