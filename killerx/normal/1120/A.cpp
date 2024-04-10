#include <bits/stdc++.h>
using namespace std;

#define ld double
#define ll long long
#define pii pair <int, int>
#define ull unsigned long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

#define PI acos(-1)
#define MOD 1000000007
#define MUL 19260817
#define EPS 1e-10
#define INF 1e9
#define LINF 1e18

template <typename T> inline void chkmin(T &x, T y) {if (y < x) x = y;}
template <typename T> inline void chkmax(T &x, T y) {if (y > x) x = y;}
template <typename T> inline T add(T x, T y) {return (x + y) % MOD;}
template <typename T> inline T mul(T x, T y) {return 1LL * x * y % MOD;}
template <typename T> inline T qp(T x, T n) {
	T ans = 1;
	do {if (n & 1) ans = mul(ans, x); x = mul(x, x);} while (n >>= 1);
	return ans;
}

#ifndef DEBUG
const int SZ = 1 << 13;
char buff[SZ], *pos = buff + SZ - 1;
#define getchar() (++ pos == buff + SZ ? fread(pos = buff, 1, SZ, stdin), *pos : *pos)
#endif

inline ll read() {
	ll x = 0; int f = 1, c = getchar();
	for (;!isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x<<3) + (x<<1) + (c^48);
	return x * f;
}

const int N = 1 << 20;
int n, k, m, s;
int a[N], b[N], nwpos[N];
int cnt[N];
vector <int> occ[N];
bool imp[N];
int need[N];
#define NO() exit(puts("-1"))

int main() {
	m = read(), k = read(), n = read(), s = read();
	rep(i, m) a[i] = read(), occ[a[i]].PB(i);
	rep(i, s) b[i] = read(), need[b[i]] ++, nwpos[b[i]] ++, imp[b[i]] = 1;
	rep(i, N) if (imp[i]) -- nwpos[i];
	rep(i, N) if (imp[i]) if (nwpos[i] >= occ[i].size()) NO();
	int mx = 0;
	rep(i, N) if (imp[i]) chkmax(mx, occ[i][nwpos[i]]);
	rep(i, m) {
//		printf("%d %d\n", i, mx);
		int del = i % k;
		if (mx - i + 1 < k) ;
		else del += mx - i + 1 - k;
		if (del <= m - n * k) {
			printf("%d\n", del);
			for (int j = i; j % k; -- j) printf("%d ", j);
			set <int> v;
			for (int j = mx; j >= i; -- j) {
				if (imp[a[j]]) cnt[a[j]] ++;
				if (imp[a[j]] && cnt[a[j]] <= need[a[j]]) v.insert(j);
			}
			int nw = 0;
			for (int j = mx; j >= i; -- j) {
				if (v.count(j)) {
					v.erase(j);
					++ nw;
				}
				else {
					if (v.size() + 1 + nw > k) printf("%d ", j + 1);
					else ++ nw;
				}
			}
			return 0;
		}
		if (imp[a[i]]) {
			nwpos[a[i]] ++;
			if (nwpos[a[i]] >= occ[a[i]].size()) NO();
			chkmax(mx, occ[a[i]][nwpos[a[i]]]);
		}
	}
	NO();
	return 0;
}