// Problem: G. Short Task
// Contest: Codeforces - Codeforces Round #713 (Div. 3)
// URL: https://codeforces.com/contest/1512/problem/G
// Memory Limit: 512 MB
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
const int N = 1e7 + 17;
int lp[N], dp[N];
ll d[N];
vector<ll> pr;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	fill(dp, dp+N, 1<<30);
	d[1] = 1;
	dp[1] = 1;
	for(int i = 2; i < N; i++) {
		if(lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for(int j = 0; j < pr.size() && pr[j] <= lp[i] && pr[j]*i < N; j++)
			lp[pr[j]*i] = pr[j];
		ll a = 1, g = 1, t = i;
		while(t%lp[i] == 0) {
			t /= lp[i];
			g *= lp[i];
			a += g;
		}
		d[i] = d[t]*a;
		if(d[i] < N)
		dp[d[i]] = min(dp[d[i]], i);
	}
	for(auto &i : dp) if(i==1<<30) i = -1;
	multitest([&](){
		int n;
		cin >> n;
		cout << dp[n] << '\n';;
	});
}
//Prod (a_i + 1) = C
//