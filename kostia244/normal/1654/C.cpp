// Problem:   
// Contest: Codeforces
// URL: https://m1.codeforces.com/contest/1654/problem/C
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
	#define int long long
	multitest([&](){
		int n;
		ll w = 0;
		cin >> n;
		vector<ll> a(n);
		map<ll, int> cnt;
		for(auto &i : a) cin >> i, w += i, cnt[i]++;
		queue<int> lft;
		lft.push(w);
		int pieces = 0;
		for(int i = 0; lft.size() && i < 4*n; i++) {
			ll x = lft.front();
			lft.pop();
			if(cnt[x]) {
				cnt[x]--;
			} else {
				lft.push(x/2);
				lft.push(x - x/2);
			}
		}
		int bad = 0;
		for(auto i : cnt) if(i.second) bad = 1;
		report(!bad);
	});
	
}