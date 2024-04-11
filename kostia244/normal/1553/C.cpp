// Problem: C. 
// Contest: Codeforces - Harbour.Space Scholarship Contest 2021-2022 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1553/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
		string s;
		cin >> s;
		int ful = 0, prog = 0;
		for(int i = 0; i < 10; i++) {
			ful |= (s[i]=='?')<<i;
			prog |= (s[i]=='1')<<i;
		}
		vector<int> A(11), B(11);
		for(int i = 9; i>=0;i--) {
			A[i] = A[i+1]+(i%2==1);
			B[i] = B[i+1]+(i%2==0);
		}
		int ans = 123;
		for(int msk = ful; 1; msk = (msk-1)&ful) {
			int a = 0, b = 0, s = msk|prog;
			int i = 0;
			for(; i < 10; i++) {
				(i%2 ? a : b)+=(s>>i)&1;
				if(a > b+B[i+1] || b > a+A[i+1])
					{i++;break;}
			}
			ans = min(ans, i);
			if(!msk) break;
		}
		cout << ans << '\n';
	});
	
}