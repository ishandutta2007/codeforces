// Problem: B. Making Towers
// Contest: Codeforces - Codeforces Round #809 (Div. 2)
// URL: https://codeforces.com/contest/1706/problem/B
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
		vector<array<int, 2>> cnt(n+1, array<int, 2>{-1, 0});
		for(int t, i = 0; i < n; i++) {
			cin >> t;
			if(cnt[t][0] == -1 || (cnt[t][0]^i)&1)
				cnt[t][1]++;
			cnt[t][0] = i;
		}
		for(int i = 1; i <= n; i++) cout << cnt[i][1] << " "; cout << '\n';
	});
	
}