// Problem: C. BA-String
// Contest: Codeforces - Educational Codeforces Round 119 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1620/problem/C
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
		int n, k;
		ll x;
		cin >> n >> k >> x;
		x--;
		string s;
		cin >> s;
		int cur = 0;
		vector<int> f;
		for(auto &i : s) {
			if(i == 'a') {
				f.push_back(cur*k);
				cur = 0;
			} else {
				cur++;
			}
		}
		f.push_back(cur*k);
		reverse(all(f));
		string res;
		for(auto i : f){
			res += string(x%(i+1), 'b');
			x /= i+1;
			res += 'a';
		}
		res.pop_back();
		reverse(all(res));
		cout << res << '\n';
	});
	
}