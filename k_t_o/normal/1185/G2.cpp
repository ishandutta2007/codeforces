#include <bits/stdc++.h>

using namespace std;

#define sz(a) int(a.size())
typedef long long ll;

const int MOD = 1e9+7;

int resP [26][26][26][4];
int perm (ll g1, ll g2, ll g3, int pv) {
	if (g1+g2+g3 == 0) return 1;
	if (resP[g1][g2][g3][pv] != -1) return resP[g1][g2][g3][pv];
	int ans = 0;

	if (pv != 1 && g1) ans = (g1*perm(g1-1, g2, g3, 1)+ans)%MOD;
	if (pv != 2 && g2) ans = (g2*perm(g1, g2-1, g3, 2)+ans)%MOD;
	if (pv != 3 && g3) ans = (g3*perm(g1, g2, g3-1, 3)+ans)%MOD;

	return resP[g1][g2][g3][pv] = ans;
}

vector <int> d, g, ps;
unordered_map<int,int> res[50][2501];
//multi    
const int H3 = 26*26;

int dp (int id, int g1, int g2, int g3, int hG, int rem) {
	if (!rem) return perm(g1,g2,g3, 0);
	if (id < 0) return 0;
	if (ps[id] < rem) return 0;
	if (res[id][rem].count(hG)) return res[id][rem][hG];

	int ans = dp(id-1, g1, g2, g3, hG, rem);
	if (rem >= d[id]) {
		if (g[id] == 1 && g1 < 25) ans += dp(id - 1, g1 + 1, g2, g3, hG + 1, rem - d[id]);
		if (g[id] == 2 && g2 < 25) ans += dp(id - 1, g1, g2 + 1, g3, hG + 26, rem - d[id]);
		if (g[id] == 3 && g3 < 25) ans += dp(id - 1, g1, g2, g3 + 1, hG + H3, rem - d[id]);
	}
	if (ans >= MOD) ans -= MOD;

	return res[id][rem][hG] = ans;
}

int main() {
	memset(resP, -1, sizeof(resP));

	int n, T;
	cin >> n >> T;
	d.resize(n), g.resize(n);
	for (int i = 0; i < n; i++) cin >> d[i] >> g[i];
	ps.resize(n);
	partial_sum(begin(d), end(d), begin(ps));

//	for(int i=0;i<n;++i)cout<<ps[i]<<endl;

	cout << dp(n-1, 0, 0, 0, 0, T) << endl;
}