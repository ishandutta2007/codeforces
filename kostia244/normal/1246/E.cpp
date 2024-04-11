// Problem: E. To Make 1
// Contest: Codeforces - Codeforces Round #596 (Div. 1, based on Technocup 2020 Elimination Round 2)
// URL: https://codeforces.com/contest/1246/problem/E
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
const int N = 16, C = 2020;
int sm[1<<N], n, k, a[N];
vector<char> dp[1<<N];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n >> k;
	for(int i = 0; i < n; i++) 
		cin >> a[i];
	for(int msk = 0; msk < 1<<n; msk++) {
		for(int j = 0; j < n; j++)
			if((msk>>j)&1)
				sm[msk] += a[j];
		dp[msk].resize(sm[msk]+1, -1);//why do I have to do this :sob:
	}
	dp[0][0] = 0;
	for(int msk = 0; msk < 1<<n; msk++) {
		for(int s = sm[msk]; s >= 0; s--) if(dp[msk][s] != -1) {
			if(s%k == 0 && dp[msk][s/k] == -1)
				dp[msk][s/k] = n;
			for(int j = 0; j < n; j++)
				if(~msk >> j & 1) {
					if(dp[msk|1<<j][s+a[j]] == -1)
						dp[msk|1<<j][s+a[j]] = j;
				}
		}
	}
	int msk = (1<<n)-1, s = 1;
	if(dp[msk][s] == -1) 
		return cout << "NO", 0;
	cout << "YES\n";
	vector<vector<int>> levels(1);
	while(msk) {
		if(dp[msk][s] == n) {
			s *= k;
			levels.emplace_back();
		} else {
			int b = dp[msk][s];
			levels.back().push_back(a[b]);
			s -= a[b];
			msk -= 1<<b;
		}
	}
	for(int i = levels.size(); i-->1;) {
		while(levels[i].size()) {
			int j = i;
			cout << levels[i].back() << " " << end(levels[i])[-2] << endl;
			int x = levels[i].back()+end(levels[i])[-2];
			levels[i].pop_back(), levels[i].pop_back();
			while(x%k==0)
				x/=k, j--;
			levels[j].push_back(x);
		}
	}
}