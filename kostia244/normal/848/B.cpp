#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<19, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, h, w, first[maxn], xx[maxn], yy[maxn];
vector<array<int, 3>> a[maxn];
int ps[maxn];
void solve(vector<array<int, 3>> &s) {
	if(s.empty()) return;
	vector<array<int, 2>> h, v;
	for(auto &[g, p, i] : s) (g == 1 ? h : v).push_back({p, i});
	sort(all(v));
	sort(all(h), greater<>());
	vector<int> p;
	for(auto i : h) p.push_back(i[1]);
	for(auto i : v) p.push_back(i[1]);
	for(int i = 0; i < p.size(); i++) {
		ps[p[i]] = p[(p.size()+i-v.size())%p.size()];
	}
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	memset(first, -1, sizeof first);
	cin >> n >> h >> w;
	for(int i = 1; i <= n; i++) ps[i] = i;
	for(int g, p, t, i = 1; i <= n; i++) {
		cin >> g >> p >> t;
		if(g == 1) xx[i] = p, yy[i] = w;
		else xx[i] = h, yy[i] = p;
		a[(maxn/2) + t-p].push_back({g, p, i});
	}
	for(int i = 0; i < maxn; i++) {
		solve(a[i]);
	}
	for(int i = 1; i <= n; i++) cout << xx[ps[i]] << " " << yy[ps[i]] << endl;
}