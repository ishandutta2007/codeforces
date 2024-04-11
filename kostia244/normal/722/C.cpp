#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<20, mod = 998244353;
int p[maxn], r[maxn], sm[maxn];
int n, a[maxn], act[maxn];
int res = 0;
int par(int v) {
	return p[v] ? p[v] = par(p[v]) : v;
}
void unite(int i, int j) {
	if(!act[i] || !act[j]) return;
	i = par(i), j = par(j);
	if(i == j) return;
	if(r[i] < r[j]) swap(i, j);
	p[j] = i;
	r[i] = j;
	sm[i] += sm[j];
	res = max(res, sm[i]);
}
void activ(int i, int v) {
	act[i] = 1;
	res = max(res, sm[i] = v);
	unite(i, i-1);
	unite(i, i+1);
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	vector<int> ord(n), ans;
	for(auto &i : ord) cin >> i;
	reverse(all(ord));
	for(auto &i : ord) {
		ans.push_back(res);
		activ(i, a[i]);
	}
	reverse(all(ans));
	for(auto &i : ans) cout << i << '\n';
}