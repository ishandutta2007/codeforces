#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
const int maxn = 1<<18, mod = 998244353;
int add(int x, int y) {
	return x+y>=mod?x+y-mod:x+y;
}
int bp(int a, int p) {
	int r = 1;
	while(p) {
		if(p&1) r = r*1ll*a%mod;
		a = a*1ll*a%mod, p>>=1;
	}
	return r;
}
template<bool inv>
void fwht(vector<int> &a) {
	int n = a.size();
	for(int d = 1; d < n; d*=2)
	for(int i = 0; i < n; i++) if(~i&d) {
		int x = a[i], y = a[i^d];
		a[i] = add(x, y);
		a[i^d] = add(x, mod-y);
	}
	if(inv) {
		int r = 1;
		for(int d = 1; d < n; d*=2) r = r * 1ll * ((mod+1)/2) %mod;
		for(int i = 0; i < n; i++) a[i] = a[i]*1ll*r%mod;
	}
}
int n, m, a[maxn];
vector<int> g[maxn];
int dfs(int v) {
	if(a[v] != -1) return a[v];
	vector<int> s;
	for(auto i : g[v]) {
		s.push_back(dfs(i));
	}
	a[v] = 0;
	sort(all(s));
	for(auto i : s) {
		a[v] += a[v] == i;
		if(a[v] < i) break;
	}
	return a[v];
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;--f, --t;
		g[f].push_back(t);
	}
	int inv = bp(n+1, mod-2);
	fill(a, a+n, -1);
	vector<int> s(1<<10);
	for(int i = 0; i < n; i++) {
		dfs(i);
		s[a[i]] = add(s[a[i]], inv);
	}
	fwht<0>(s);
	for(int i = 0; i < s.size(); i++) {
		s[i] = bp(mod+1-s[i], mod-2);
	}
	fwht<1>(s);
	cout << (mod+1 - s[0]*1ll*inv%mod)%mod << endl;
}