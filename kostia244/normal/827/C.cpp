#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<20, mod = 1e9 + 7;
struct fenwick {
	vector<int> f;
	int n;
	fenwick(int n = 0) : n(n), f(n+1) {}
	void add(int v, int x) {
		for(; v <= n; v += v&-v) f[v]+=x;
	}
	int get(int v) {
		int r = 0;
		for(; v; v -= v&-v) r += f[v];
		return r;
	}
	int get(int l, int r) { 
		if(l > r) return 0;
		return get(r) - get(max(0, l-1));
	}
};
fenwick f[11][10][4];
int n;
string s;
int id[256];
inline void touch(int p, char c, int t) {	
	for(int x = 1; x <= 10; x++) {
		f[x][p%x][id[c]].add(1 + (p/x), t);
	}
}
inline int count(int m, int rm, char c, int l, int r) {
	if(l%m < rm) l -= l%m, l += rm;
	if(l%m > rm) l -= l%m, l += m+rm;
	if(r%m < rm) r -= m + (r%m), r += rm;
	if(r%m > rm) r -= r%m, r += rm;
	if(l > r) return 0;
	return f[m][rm][id[c]].get((l/m) + 1, (r/m) + 1);
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	id['A'] = 0;
	id['G'] = 1;
	id['T'] = 2;
	id['C'] = 3;
	cin >> s; n = s.size();
	s = " " + s;
	for(int i = 1; i <= 10; i++)
		for(int r = 0; r < i; r++)
		for(int j = 0; j < 4; j++)
			f[i][r][j] = fenwick((n/i) + 3);
	for(int i = 1; i <= n; i++) touch(i, s[i], 1);
	int q; cin >> q;
	int t, l, r;
	char c;
	string e;
	while(q--) {
		cin >> t;
		if(t == 1) {
			cin >> l >> c;
			touch(l, s[l], -1);
			touch(l, s[l] = c, 1);
		} else {
			cin >> l >> r >> e;
			int ans = 0;
			for(int i = 0; i < e.size(); i++) ans += count(e.size(), (l+i)%e.size(), e[i], l, r);
			cout << ans << endl;
		}
	}
}