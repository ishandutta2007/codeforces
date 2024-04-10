#include <bits/stdc++.h>
#define pb push_back
#define LOG(FMT...) fprintf(stderr, FMT)
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n, m, len[N], lg[N];
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll mul(ll a, ll b, ll p) {
	a = (a % p + p) % p; b = (b % p + p) % p;
	ll r = a * b - (ll)((long double) a * b / p) * p;
	return r < 0 ? r + p : r;
}
ll exgcd(ll a, ll b, ll &x, ll &y) {
	if(!b) return x = 1, y = 0, a;
	ll g = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return g;
}
struct node {
	int x, y;
};
vector<node> pos[N];
struct crt {
	ll t, p; //mod p = t
} st[N][20];
int q, la;
crt uni(crt a, crt b) {
	if(!~a.p || !~b.p) return crt{0, -1};
//	LOG("x = %lld (mod %lld), x = %lld (mod %lld) -> \n", a.t, a.p, b.t, b.p);
	ll x, y, g = exgcd(a.p, b.p, x, y);
	if((b.t - a.t) % g) return crt{0, -1};
	ll c = b.p / g;
	x = mul(x, (b.t - a.t) / g, c);
	ll mod = a.p * c;
	crt res = crt{(a.t + mul(a.p, x, mod)) % mod, mod};
//	LOG("x = %lld (mod %lld)!\n", res.t, res.p);
	return res;
}
int work() {
	int w = lg[q], z = 0;
	rep(i, 1, w) rep(j, 1, q - (1 << i) + 1)
		st[j][i] = uni(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
	rep(i, 1, q) {
		int u = i - 1;
		crt now = {0, 1}, nxt;
		per(j, w, 0) if(u + (1 << j) <= q && ~(nxt = uni(now, st[u + 1][j])).p) {
			u += 1 << j;
			now = nxt;
		}
		z = max(z, u - i + 1);
	}
	return z;
}
int solve(int c) {
	int sz = int(pos[c].size());
	if(!sz) return 0;
	int z = 0; q = 0;
	for(int i = 0; i < sz; i ++) {
		node &cur = pos[c][i];
		if(q && la < cur.x - 1) {
			if(q > z) z = max(z, work());
			q = 0;
		}
		st[++ q][0] = crt{cur.y, len[cur.x]};
		la = cur.x;
	}
	if(q > z) z = max(z, work());
	return z;
}
int main() {
//	crt z = uni(crt{3, 6}, crt{1, 4}); printf("x = %lld mod %lld\n", z.t, z.p);
	scanf("%d%d", &n, &m);
	rep(i, 2, n) lg[i] = lg[i >> 1] + 1;
	int k, x;
	rep(i, 1, n) {
		scanf("%d", &k);
		len[i] = k;
		rep(j, 1, k) {
			scanf("%d", &x);
			pos[x].pb({i, j - 1});
		}
	}
	rep(i, 1, m) {
		printf("%d\n", solve(i));
	}
//	cerr << "time: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}