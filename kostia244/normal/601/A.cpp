#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 403;
int n, m, mat[maxn][maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		mat[f][t] = mat[t][f] = 1;
	}
	if(mat[1][n]) {
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++) {
				if(i!=j) {
					mat[i][j]^=1;
				}
			}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) {
			if(i!=j) {
				if(!mat[i][j]) mat[i][j] = 1<<20;
			}
		}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				mat[i][j] = min(mat[i][k]+mat[k][j], mat[i][j]);
	if(mat[1][n] > n) mat[1][n]=-1;
	cout << mat[1][n];
}