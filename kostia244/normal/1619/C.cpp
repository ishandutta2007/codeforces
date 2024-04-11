// Problem: C. Wrong Addition
// Contest: Codeforces - Codeforces Round #762 (Div. 3)
// URL: https://codeforces.com/contest/1619/problem/C
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
		string a, s;
		cin >> a >> s;
		string b;
		reverse(all(a));
		reverse(all(s));
		int j = 0;
		for(auto &i : a) {
			while(j >= s.size()) s += "0";
			if(s[j] < i) {
				b += 10+s[j]-i+'0';
				j++;
			} else {
				b += s[j]-i+'0';
			}
			j++;
		}
		while(j < s.size()) b += s[j++];
		string t;
		for(int i = 0; i < max(a.size(), b.size()); i++) {
			if(a.size() <= i) a += "0";
			if(b.size() <= i) b += "0";
			t += to_string((a[i]-'0')+(b[i]-'0'));
			if((a[i]-'0')+(b[i]-'0')>9)
				swap(t.back(), end(t)[-2]);
		}
		while(t.back() == '0') t.pop_back();
		while(s.back() == '0') s.pop_back();
		while(b.back() == '0') b.pop_back();
		reverse(all(b));
		if(s != t) b = "-1"; 
		cout << b << '\n';
	});
	
}