//#pragma GCC optimize("trapv")
#pragma GCC optimize("O2")
//#pragma GCC target("avx,avx2,sse,sse2,tune=native,fma")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
const int maxn = 1e2 + 30;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
using ld = double;
struct mat{
	ld m[maxn][maxn];
	mat() {
		memset(m, 0, sizeof m);
	}
};
int n, x;
mat mul(mat a, mat b) {
	mat c;
	for(int i = 0; i < 128; i++)
		for(int j = 0; j < 128; j++)
			for(int k = 0; k < 128; k++) {
				c.m[i][j] += a.m[i][k]*b.m[k][j];
			}
	return c;
}
mat pw(mat mt, int p) {
	mat c;
	for(int i = 0; i < 128; i++)
		c.m[i][i]=1;
	while(p) {
		if(p&1) c = mul(c, mt);
		mt = mul(mt, mt);
		p>>=1;
	}
	return c;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> x;
	x++;
	mat m;
	ld t;
	for(int i = 0; i < x; i++) {
		cin >> t;
		for(int j = 0; j < 128; j++)
			m.m[j][j^i] = t;
	}
	m = pw(m, n);
	cout << fixed << setprecision(15) << 1.-m.m[0][0];
}