#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define pb push_back
#include <x86intrin.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 5e2 + 55, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, k, q;
int mat[maxn][maxn], rm[maxn][maxn], rr[maxn][maxn];
struct mn {
	deque<int> a;
	void push(int x) {
		while(!a.empty() && a.back() < x) a.pop_back();
		a.push_back(x);
	}
	void rem(int x) {
		if(!a.empty() && a.front() == x) a.pop_front();
	}
	int getMax() {
		return a.front();
	}
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x, y, t, q;
	cin >> n >> m >> k >> q;
	memset(mat, 0x4f, sizeof mat);
	while(q--) {
		cin >> x >> y >> t;
		mat[x][y] = t;
	}
	for(int i = 1; i <= n; i++) {
		mn t;
		for(int j = 1; j <= m; j++) {
			t.push(mat[i][j]);
			if(j-k>0) t.rem(mat[i][j-k]);
			if(j>=k)
				rm[i][j] = t.getMax();
		}
	}
	int ans = 1<<30;
	for(int j = k; j <= m; j++) {
		mn t;
		for(int i = 1; i<= n; i++) {
			t.push(rm[i][j]);
			if(i-k>0) t.rem(rm[i-k][j]);
			if(i>=k) ans = min(ans, t.getMax());
		}
	}
	if(ans == 1<<30) ans = -1;
	cout << ans;
}