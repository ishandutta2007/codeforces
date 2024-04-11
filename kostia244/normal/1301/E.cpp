#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<int, int>;
using vpi = vector<pair<int, int>>;
using namespace __gnu_pbds;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 5e2 + 10;
#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
inline void getch(char &x) {
	while (x = getchar_unlocked(), x < 33) {
		;
	}
}
template<typename T> inline bool sc(T &num) {
	bool neg = 0;
	int c;
	num = 0;
	while (c = getchar_unlocked(), c < 33) {
		if (c == EOF)
			return false;
	}
	if (c == '-') {
		neg = 1;
		c = getchar_unlocked();
	}
	for (; c > 47; c = getchar_unlocked())
		num = num * 10 + c - 48;
	if (neg)
		num *= -1;
	return true;
}
const int sz1 = maxn*maxn;
const int sz2 = maxn, msz = maxn;
int n, m, q;
char mat[maxn*maxn], col[2][2] = {{'R', 'G'}, {'Y', 'B'}};
short sq[maxn*maxn], logo[maxn*maxn], cmax[2*maxn*maxn*maxn];
const int bias = maxn-5;
inline int check(int i, int j) {
	int l = sq[i*msz + j];
	if(i+2*l-1>n||j+2*l-1>m) return 0;
	for(int x = 0; x < 2; x++)
		for(int y = 0; y < 2; y++) {
			if(mat[msz*(i+x*l) + j+y*l]!=col[x][y]) return 0;
			if(sq[msz*(i+x*l) + j+y*l]<l) return 0;
		}
	return 2*l;
}
inline void read() {
	sc(n), sc(m), sc(q);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			getch(mat[i*msz + j]);
		}
	}
	for (int i = n; i; i--) {
		for (int j = m; j; j--) {
			if (i + 1 > n || j + 1 > m) {
				sq[i*msz + j] = 1;
			} else {
				if (mat[msz*(i + 1) + j] == mat[msz*i + j] && mat[msz*i + j] == mat[msz*i + j + 1]) {
					int t = min(sq[msz*(i + 1) + j], sq[i*msz + j + 1]);
					if (i + t <= n && j + t <= m
							&& mat[i*msz + j] == mat[msz*(i + t) + j + t])
						t++;
					sq[i*msz + j] = t;
				} else {
					sq[i*msz + j] = 1;
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			logo[i*msz + j] = check(i, j);
		}
	}
	for(int d = 1-m; d <= n-1; d++) {
		for(int rx = n; rx; rx--) {
			int ry = rx-d;
			cmax[sz1*(bias+d) + sz2*rx + rx] = 0;
			for(int lx = rx-1; lx; lx--) {
				int ly = lx-d;
				cmax[sz1*(bias+d) + sz2*lx + rx] = cmax[sz1*(bias+d) + sz2*(lx+1) + rx];
				if(lx+logo[lx*msz + ly]-1<=rx&&ly+logo[lx*msz + ly]-1<=ry) {
					cmax[sz1*(bias+d) + sz2*lx + rx] = max(cmax[sz1*(bias+d) + sz2*lx + rx], logo[lx*msz + ly]);
				}
			}
		}
	}
}
inline void solve() {
	int lx, rx, ly, ry;
	while(q--) {
//		cin >> lx >> ly >> rx >> ry;
		sc(lx), sc(ly), sc(rx), sc(ry);
		short ans = 0;
		for(int i = ly; i <= ry; i++) {//(lx, y)
			int d = bias+lx-i, len = min(rx-lx, ry-i);
			if(ans>len) break;
			ans = max(ans, cmax[d*sz1 + sz2*lx + lx+len]);
		}
		for(int i = lx; i <= rx; i++) {//(i, ly)
			int d = bias+i-ly, len = min(rx-i, ry-ly);
			if(ans>len) break;
			ans = max(ans, cmax[d*sz1 + i*sz2 + i+len]);
		}
		printf("%d\n", (int)ans*(int)ans);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	solve();
	return 0;
}