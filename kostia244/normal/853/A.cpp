#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<int, int>;
const int maxn = 3e5 + 55;//, mod = 1e9 + 7;
int n, k;
vi a;
int ans[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	a.resize(n);
	for(auto &i : a) cin >> i;
	int j = 0;
	multiset<pi, greater<pi>> cst;
	ll res = 0;
	for(int i = k+1; i <= k+n; ++i) {
		while(j < n && j+1 <= i) cst.insert({a[j], ++j});
		ans[cst.begin()->second] = i;
		res += (i-cst.begin()->second) * 1ll * cst.begin()->first;
		cst.erase(cst.begin());
	}
	cout << res << '\n';
	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
}