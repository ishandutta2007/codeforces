#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define pow loli
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<18, inf = 1<<26;
struct node {
	int cst[5][5];
	node() { for(int i = 0; i < 25; i++) cst[i/5][i%5] = inf; }
	node(char c) {
		for(int i = 0; i < 25; i++) cst[i/5][i%5] = inf*((i/5)!=(i%5));
		if(c == '2') {
			cst[0][0] = 1;
			cst[0][1] = 0;
		}
		if(c == '0') {
			cst[1][1] = 1;
			cst[1][2] = 0;
		}
		if(c == '1') {
			cst[2][2] = 1;
			cst[2][3] = 0;
		}
		if(c == '7') {
			cst[3][3] = 1;
			cst[3][4] = 0;
		}
		if(c == '6') {
			cst[3][3] = 1;
			cst[4][4] = 1;
		}
	}
	friend node operator+(const node &a, const node &b) {
		node c;
		for(int i = 0; i < 5; i++)
			for(int j = 0; j < 5; j++)
				for(int k = 0; k < 5; k++)
					c.cst[i][j] = min(c.cst[i][j], a.cst[i][k] + b.cst[k][j]);
		return c;
	}
};
node tree[2*maxn];
int n, m;
string s;
int get(int l, int r) {
	node resl('9'), resr('9');
	for(l += n, r += n+1; l < r; l>>=1, r>>=1) {
		if(l&1) resl = resl + tree[l++];
		if(r&1) resr = tree[--r] + resr;
	}
	resl = resl + resr;
	return resl.cst[0][4];
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> s;
	for(int i = 0; i < n; i++) tree[n+i] = node(s[i]);
	for(int i = n; i--;) tree[i] = tree[i*2] + tree[i*2 + 1];
	for(int l, r; m--;) {
		cin >> l >> r;--l,--r;
		int ans = get(l, r);
		if(ans > n) ans = -1;
		cout << ans << '\n';
	}
	return 0;
}