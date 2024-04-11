// Problem: C. Complex Market Analysis
// Contest: Codeforces - Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1609/problem/C
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
const int N = 10000000;
vector<int> lp(N+1);
vector<int> pr;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	#define int long long
	for (int i=2; i <= N; ++i) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.push_back(i);
	    }
	    for (int j=0; j < (int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= N; ++j) {
	        lp[i * pr[j]] = pr[j];
	    }
	}
	multitest([&](){
		int n, e;
		cin >> n >> e;
		vector<int> a(n), co(2*n), ro(2*n);
		for(auto &i : a) cin >> i;
		for(int i = n; i--;) {
			if(a[i] == 1)
				co[i] = 1+co[i+e];
		}
		for(int i = 0; i < n; i++) {
			if(a[i] == 1)
				ro[i] = i-e<0?1:1+ro[i-e];
		}
		int ans = 0;
		for(int i = 0; i < n; i++) {
			if(a[i]>1 && lp[a[i]] == a[i]) {
				ll cnt = i-e<0?1:1+ro[i-e];
				cnt *= 1+co[i+e];
				ans += cnt-1;
			}
		}
		cout << ans << '\n';
	});
	
}