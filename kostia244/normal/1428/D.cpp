#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define apply fuckstl
#define int long long
using namespace std;
using ll = int64_t;
const int maxn = 1<<18, mod = 1000000007;
int a[maxn], r[maxn], mr = 1;
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<array<int, 2>> pts;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] == 1) {
			pts.push_back({i, mr});
			r[i] = mr++;
		}
	}
	vector<int> L[3];
	for(int i = n; i; i--) {
		if(a[i] == 1) L[0].push_back(i);//insert 0
		if(a[i] == 2) {//search for one
			if(L[0].empty()) return cout << -1, 0;
			int x = L[0].back();
			pts.push_back({i, r[x]});
			//cout << i << " - " << L[0].back() << '\n';
			L[0].pop_back();
			L[1].push_back(i);
		}
		if(a[i] == 3) {//search for one or 2
			if(L[0].size() + L[1].size() + L[2].size() == 0) return cout << -1, 0;
			int q = 2;
			while(L[q].empty()) q--;
			pts.push_back({i, mr});
			pts.push_back({L[q].back(), mr});
			//cout << i << " - " << L[q].back() << '\n';
			L[q].pop_back();
			L[2].push_back(i);
			mr++;
		}
	}
	cout << pts.size() << '\n';
	for(auto [x, y] : pts) cout << n+1-y << " " << x << '\n';
}