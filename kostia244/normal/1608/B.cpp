// Problem: B. Build the Permutation
// Contest: Codeforces - Codeforces Round #758 (Div.1 + Div. 2)
// URL: https://codeforces.com/contest/1608/problem/B
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
vector<int> solve(int n, int a, int b) {
	if(abs(a-b) > 1 || a+b > n-2) {
		return {};
	}
	int rev = 0;
	if(a < b) swap(a, b), rev = 1;
	vector<int> ans(n);
	if(a==b) {
		a++;
		for(int i = 0; i < a; i++)
			ans[2*i] = i+1;
		for(int i = 0; i < a; i++)
			ans[2*i+1] = a+i+1;
		for(int i = 2*a; i < n; i++)
			ans[i] = i+1;
	} else if(a == b+1) {
		int start = n - 2*a;
		for(int i = 0; i <= a; i++)
			ans[2*i] = start+i;
		for(int i = 0; i < a; i++)
			ans[2*i+1] = start+a+1+i;
		for(int x = 1, i = n-1; i > 2*a; i--)
			ans[i] = x++;
	}
	if(rev)
		for(auto &i : ans)
			i = n-i+1;
	return ans;
}
int main() {
	cin.tie(0)->sync_with_stdio(0); 
	for(int n = 2; n <= 40; n++) {
		for(int a = 0; a <= n; a++) {
			for(int b = 0; a+b <= n; b++) {
				auto ans = solve(n, a, b);
				if(ans.empty()) continue;
				int x = 0, y = 0;
				for(int i = 1; i+1 < n; i++)
					x += ans[i] > max(ans[i-1],ans[i+1]);
				for(int i = 1; i+1 < n; i++)
					y += ans[i] < min(ans[i-1], ans[i+1]);
				assert(a == x && b == y);
			}
		}
	}
	int n = 8;
	// vector<int> ans(n);
	// iota(all(ans), 0);
	// do {
		// int x = 0, y = 0;
		// for(int i = 1; i+1 < n; i++)
			// x += ans[i] > max(ans[i-1],ans[i+1]);
		// for(int i = 1; i+1 < n; i++)
			// y += ans[i] < min(ans[i-1], ans[i+1]);
		// assert(abs(x-y)<2 && x+y <= n-2 && x+y>0);
	// } while(next_permutation(all(ans)));
	multitest([&](){
		int n, a, b;
		cin >> n >> a >> b;
		auto ans = solve(n, a, b);
		if(ans.empty())
			cout << "-1\n";
		else {
			for(auto i : ans)
				cout << i << " "; cout << '\n';
		}
	});
	
}