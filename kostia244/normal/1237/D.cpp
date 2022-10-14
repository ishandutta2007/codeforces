#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define apply fuckstl
using namespace std;
using ll = int64_t;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &i : a) cin >> i;
	if(*min_element(all(a)) * 2 >= *max_element(all(a))) {
		for(int i = 0; i < n; i++) cout << "-1 "; cout << endl;
		return 0;
	}
	for(int i = 0; i < 2*n; i++) a.push_back(a[i]);
	n *= 3;
	multiset<int> qq;
	vector<int> ans(n/3);
	for(int cur = 0, i = 0; i < n/3; i++) {
		while(cur < n && (qq.empty() || a[cur]*2 >= *qq.rbegin())) {
			qq.insert(a[cur++]);
		}
		ans[i] = cur-i;
		qq.erase(qq.find(a[i]));
	}
	for(auto i : ans) cout << i << " "; cout << '\n';
}