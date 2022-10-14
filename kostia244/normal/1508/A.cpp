// Problem: A. Binary Literature
// Contest: Codeforces - Codeforces Round #715 (Div. 1)
// URL: https://codeforces.com/contest/1508/problem/A
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
		string a, b, c;
		cin >> n >> a >> b >> c;
		int A = count(all(a), '0')>=n;
		int B = count(all(b), '0')>=n;
		int C = count(all(c), '0')>=n;
		auto get = [](string a, string b, int rev) {
			if(rev) {
				for(auto &i : a) i ^= '0'^'1';
				for(auto &i : b) i ^= '0'^'1';
			}
			string res;
			int i = 0, j = 0, f = a.size()/2;
			for(; f--;) {
				while(i<a.size()&&a[i]!='0') res.push_back(a[i++]);
				while(j<b.size()&&b[j]!='0') res.push_back(b[j++]);
				res.push_back('0'), i++, j++;
			}
			while(i < a.size()) res += a[i++];
			while(j < b.size()) res += b[j++];
			if(rev)
				for(auto &i : res) i ^= '0'^'1';
			return res;
		};
		if(A==B) {
			cout << get(a, b, !A) << '\n';
		} else if(B==C) {
			cout << get(c, b, !C) << '\n';
		} else {
			cout << get(c, a, !C) << '\n';
		}
	});
	
}