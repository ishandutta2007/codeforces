#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<20, mod = 998244353;

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	int n = s.size();
	s = s + s;
	vector<int> dp{0};
	char lst = '\0';
	for(auto &i : s) {
		dp.push_back(1 + dp.back()*(i != lst));
		lst = i;
		//cout << dp.back() << " " << i << endl;
	}
	cout << min(*max_element(all(dp)), n);
}