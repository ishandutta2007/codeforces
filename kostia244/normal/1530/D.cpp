// Problem: D. Secret Santa
// Contest: Codeforces - Codeforces Round #733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine))
// URL: https://codeforces.com/contest/1530/problem/D
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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n;
		cin >> n;
		vector<int> a(n), hv(n+1), bp, mexar;
		int ans = 0, dup = 0, pos = 0;
		for(auto &i : a) {
			cin >> i;
			if(!hv[i]++) ans++;
			else dup = i, bp.push_back(pos);
			pos++;
		}
		for(int i = 1; i <= n; i++) if(!hv[i])
			mexar.push_back(i);
		if(ans == n-1) {
			for(int i = 0; i < n; i++) if(a[i] == dup && i+1 != mexar[0]) {
				a[i] = mexar[0];
				break;
			}
		} else {
			mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
			while(true) {
				shuffle(all(mexar), rng);
				int suck = 0;
				for(int i = 0; i < mexar.size(); i++) if(bp[i]+1 == mexar[i]) suck = 1;//, cout << bp[i]+1 << " == " << mexar[i] << endl;;
				if(suck) continue;
				for(int i = 0; i < mexar.size(); i++) a[bp[i]] = mexar[i];//, cout << bp[i]+1 << " == " << mexar[i] << endl;
				break;
			}
		}
		cout << ans << '\n';
		for(auto i : a) cout << i << " "; cout << endl;
	});
	
}