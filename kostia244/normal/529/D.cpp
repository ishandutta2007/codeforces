#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 5050;
int n, m, T;
int read() {
	string s;cin >> s;
	int hr = stoi(s.substr(0, 2));
	int mn = stoi(s.substr(3, 2));
	int sc = stoi(s.substr(6, 2));
	return hr*60*60 + mn*60 + sc;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> T;
	vector<int> f;
	for(int i = n; i--;) f.push_back(read());
	vector<int> ans{1};
	int ok = m==1;
	for(int cur = 1, j = 0, i = 1; i < n; i++) {
		while(f[i]-f[j]>=T) j++;
		if(j >= ans.size() || ans.back()-ans[j]+1 < m) cur++;
		ans.push_back(cur);
		ok |= ans.back()-ans[j]+1 == m;
	}
	if(!ok) return cout << "No solution\n", 0;
	cout << ans.back() << '\n';
	for(auto i : ans) cout << i << '\n';
}