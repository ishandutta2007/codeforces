#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1<<20, mod = 119<<23|1;
int c[101];
int n, m;
string s;
const int sz = 2;
struct mat {
	int a[sz][sz];
	mat() {
		memset(a, 0, sizeof a);
	}
	friend mat operator*(const mat& a, const mat& b) {
		mat c;
		for(int i = 0; i < sz; i++)
			for(int j = 0; j < sz; j++)
				for(int k = 0; k < sz; k++)
					c.a[i][j] = (c.a[i][j] + a.a[i][k]*1ll*b.a[k][j])%mod;
		return c;
	}
};
mat t[maxn];
int get(int p, int l) {
	string f = s.substr(p, l);
	reverse(f.begin(), f.end());
	if(f.size() == 2 && stoi(f) < 10) return 100;
	return stoi(f);
}
void upd(int p) {
	if(p>=n||p<0) return;
	mat val;
	val.a[1][0] = 1;
	val.a[0][0] = c[get(p, 1)];
	if(p >= 1)
		val.a[0][1] = c[get(p-1, 2)];
	for(t[p += n] = val; p>>=1;) t[p] = t[p<<1|1] * t[p<<1];
}
int query() {
	mat resl;resl.a[0][0] = resl.a[1][1] = 1;
	mat resr = resl;
	for(int l = n, r = 2*n; l < r; l>>=1, r>>=1) {
		if(l&1) {resl = t[l++] * resl;}
		if(r&1) {resr = resr * t[--r];}
	}
	resl = resr * resl;
	return resl.a[0][0];
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	for(int i = 0; i <= 9; i++)
		for(int j = 0; j <= 9; j++)
			c[i+j]++;
	cin>>n>>m>>s;
	reverse(s.begin(), s.end());
	for(int i = 0; i < n; i++) upd(i);
	for(int x, d, i = 0; i < m;i++) {
		cin >> x >> d;x = n-x;
		s[x] = '0'+d;
		upd(x+1), upd(x);
		cout << query() << '\n';
	}
}