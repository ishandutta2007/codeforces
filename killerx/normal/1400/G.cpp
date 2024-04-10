#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mod = 998244353;

int qp(int x, int n) { return n ? 1LL * qp(1LL * x * x % mod, n >> 1) * (n & 1 ? x : 1) % mod : 1; }
int inv(int x) { return qp(x, mod - 2); }

const int mxn = 3e5 + 5;
int n, m, l[mxn], r[mxn], c[mxn], e[mxn][2], id[mxn];
int fac[mxn], ifac[mxn], f[1 << 20][45];

int comb(int n, int m) {
	if (m < 0 || m > n) return 0;
	return 1LL * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

#define cntbits __builtin_popcountll

int main() {
	rep(i, mxn) fac[i] = i ? 1LL * i * fac[i - 1] % mod : 1;
	ifac[mxn - 1] = inv(fac[mxn - 1]);
	for (int i = mxn - 1; i; -- i) ifac[i - 1] = 1LL * i * ifac[i] % mod;
	scanf("%d %d", &n, &m);
	rep(i, n) scanf("%d %d", &l[i], &r[i]);
	vector <int> ve;
	rep(i, m) {
		scanf("%d %d", &e[i][0], &e[i][1]);
		-- e[i][0]; -- e[i][1];
		ve.pb(e[i][0]); ve.pb(e[i][1]);
	}
	sort(ve.begin(), ve.end());
	ve.erase(unique(ve.begin(), ve.end()), ve.end());
	vector <int> sepr; sepr.pb(1); sepr.pb(n + 1);
	rep(i, m) sepr.pb(l[e[i][0]]), sepr.pb(r[e[i][0]] + 1), sepr.pb(l[e[i][1]]), sepr.pb(r[e[i][1]] + 1);
	sort(sepr.begin(), sepr.end()); sepr.erase(unique(sepr.begin(), sepr.end()), sepr.end());
	memset(id, -1, sizeof(id));
	rep(i, ve.size()) id[ve[i]] = i;
	rep(i, m) e[i][0] = id[e[i][0]], e[i][1] = id[e[i][1]];
	rep(i, n) c[l[i]] ++, c[r[i] + 1] --;
	rep(i, mxn) if (i) c[i] += c[i - 1];
	f[0][0] = 1;
	rep(i, m) {
		rep(S, 1 << i) {
			int nS = S | 1 << i;
			rep(k, 2) {
				int rS = 0;
				ll fre = (1LL << e[i][0]) | (1LL << e[i][1]);
				rep(j, i) if (S >> j & 1) fre |= (1LL << e[j][0]) | (1LL << e[j][1]);
				fre &= ~(1LL << e[i][k]);
				rep(j, i) if (S >> j & 1) {
					if (e[j][0] == e[i][k] || e[j][1] == e[i][k]) ;
					else rS |= 1 << j, fre &= ~((1LL << e[j][0]) | (1LL << e[j][1]));
				}
				int cfre = cntbits(fre);
				for (int a = 0; a <= cfre; ++ a)
					for (int b = 0; f[rS][b]; ++ b)
						(f[nS][a + b] += 1LL * comb(cfre, a) * f[rS][b] % mod) %= mod;
			}
			// both not
			int rS = 0;
			ll fre = 0;
			rep(j, i) if (S >> j & 1) fre |= (1LL << e[j][0]) | (1LL << e[j][1]);
			fre &= ~((1LL << e[i][0]) | (1LL << e[i][1]));
			rep(j, i) if (S >> j & 1) {
				if (e[j][0] == e[i][0] || e[j][1] == e[i][0]) ;
				else if (e[j][0] == e[i][1] || e[j][1] == e[i][1]) ;
				else rS |= 1 << j, fre &= ~((1LL << e[j][0]) | (1LL << e[j][1]));
			}
			int cfre = cntbits(fre);
			for (int a = 0; a <= cfre; ++ a)
				for (int b = 0; f[rS][b]; ++ b)
					(f[nS][a + b] += mod - 1LL * comb(cfre, a) * f[rS][b] % mod) %= mod;
		}
	}
	int ans = 0;
	rep(i, sepr.size() - 1) {
		int L = sepr[i], R = sepr[i + 1] - 1;
		int O = 0;
		ll iO = 0;
		rep(j, m) if (l[ve[e[j][0]]] <= L && R <= r[ve[e[j][0]]] && l[ve[e[j][1]]] <= L && R <= r[ve[e[j][1]]])
			O |= 1 << j, iO |= (1LL << e[j][0]) | (1LL << e[j][1]);
		for (int j = L; j <= R; ++ j) if (c[j] >= j) {
			rep(a, cntbits(iO) + 1) {
				(ans += 1LL * comb(c[j] - cntbits(iO), j - a) * f[O][a] % mod) %= mod;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}