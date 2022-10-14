#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define int ll
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<20, mod = 998244353;
array<int, 2> rec(int dif, int sum) {
	return {(dif+sum)/2, (sum-dif)/2};
}
vector<array<int, 2>> solve(int c) {
	vector<array<int, 2>> r;
	for(int i = 1; i*i <= c; i++) {
		if(c%i) continue;
		if((i+ (c/i))%2 == 0) {
			r.push_back(rec(i, c/i));
			r.push_back(rec(c/i, i));
		}
	}
	for(auto &i : r) if(i[0] > i[1]) swap(i[0], i[1]);
	return r;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	int lst = 0;
	vector<int> ans;
	for(int t, i = 0; i < n/2; i++) {
		cin >> t;
		int cur = 1<<30, tt = -1;
		for(auto [a, b] : solve(t)){
			if(a != b && lst < a) {
				if(cur > b) cur = b, tt = a;
			}
		}
		if(tt == -1) return cout << "No\n", 0;
		lst = cur;
		ans.push_back(tt);
		ans.push_back(cur);
	}
	cout << "Yes\n";
	lst = -1;
	for(auto &i : ans) cout << (lst == -1 ? i*i : i*i - lst*lst) << " ", lst = i; cout << '\n';
}