#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using ll = long long;
#define int ll
using namespace std;
const int maxn = 1<<19;
const int inf = 1e18;
int32_t main() {
	ios::sync_with_stdio(0);
	vector<string> s;
	for(int i = 1; i < 10; i++)
		for(int j = i; j < 10000; j = j*10+i) s.push_back(to_string(j));
	sort(all(s));
	int t;string x;
	cin>>t;
	//for(auto i : s) cout << i << endl;
	while(t--) {
		cin >> x;
		int ans = 0;
		for(int i = 0; i < s.size() && s[i] <= x; i++) ans += s[i].size();
		cout << ans << '\n';
	}
	return 0;
}