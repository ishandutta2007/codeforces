#include <bits/stdc++.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

typedef long long ll;

int mod;

struct Mat {
	int n, m;
	int a[2][2];

	Mat(int n = 0, int m = 0): n(n), m(m) {
		memset(a, 0, sizeof(a));
	}
};

Mat operator * (const Mat &a, const Mat &b) {
	Mat ans(a.n, b.m);
	rep(i, ans.n) rep(j, ans.m) rep(k, a.m)
		(ans.a[i][j] += (ll)a.a[i][k] * b.a[k][j] % mod) %= mod;
	return ans;
}

Mat pow(Mat x, ll n) {
	Mat ans(x.n, x.m);
	rep(i, x.n) ans.a[i][i] = 1 % mod;
	for (; n; n >>= 1, x = x * x) if (n & 1) ans = ans * x;
	return ans;
}

const int mxn = 1 << 16;

int n, m;
ll k;
int s[mxn];
Mat prod[mxn << 1];
std::vector <std::pair <ll, int> > pnt;
std::map <ll, int> pntval;

void init() {
	for (int i = 0; i < n; ++ i) {
		Mat trans(2, 2);
		trans.a[0][0] = s[i];
		trans.a[0][1] = s[(i - 1 + n) % n];
		trans.a[1][0] = 1 % mod;
		trans.a[1][1] = 0 % mod;
		prod[i + mxn] = trans;
	}
	for (int i = mxn - 1; i; -- i) {
		prod[i] = prod[i << 1 | 1] * prod[i << 1];
	}
}

Mat query(int l, int r) {
	Mat L(2, 2);
	L.a[0][0] = L.a[1][1] = 1 % mod;
	Mat R(2, 2);
	R.a[0][0] = R.a[1][1] = 1 % mod;
	for (l += mxn, r += mxn; l < r; l >>= 1, r >>= 1) {
		if (l & 1) L = prod[l ++] * L;
		if (r & 1) R = R * prod[-- r];
	}
	return R * L;
}

Mat query_seq(ll l, ll r) {
	if (l / n == r / n) return query(l % n, r % n);
	Mat temp = pow(query(0, n), r / n - l / n - 1);
	return query(0, r % n) * temp * query(l % n, n);
}

int gets(ll x) {
	return pntval.find(x) != pntval.end() ? pntval[x] : s[x % n];
}

void mov(Mat &vec, ll p) {
	Mat trans(2, 2);
	trans.a[0][0] = gets(p);
	trans.a[0][1] = gets(p - 1);
	trans.a[1][0] = 1 % mod;
	trans.a[1][1] = 0 % mod;
	vec = trans * vec;
}

int main() {
	scanf("%lld %d", &k, &mod);
	scanf("%d", &n);
	rep(i, n) {
		scanf("%d", &s[i]);
		s[i] %= mod;
	}
	scanf("%d", &m);
	if (k == 0) {
		printf("%d\n", 0 % mod);
		return 0;
	}
	if (k == 1) {
		printf("%d\n", 1 % mod);
		return 0;
	}
	rep(i, m) {
		ll x; int y;
		scanf("%lld %d", &x, &y);
		if (x > k) continue;
		y %= mod;
		pnt.push_back({x, y});
		pntval[x] = y;
	}
	init();
	pnt.push_back({1, s[1]});
	pnt.push_back({k, gets(k)});
	sort(pnt.begin(), pnt.end());
	pnt.erase(unique(pnt.begin(), pnt.end()), pnt.end());
	Mat vec(2, 1);
	vec.a[0][0] = 1 % mod;
	vec.a[1][0] = 0 % mod;
	for (int i = 1; i < pnt.size(); ++ i) {
		if (pnt[i].first == pnt[i - 1].first + 1)
			mov(vec, pnt[i - 1].first);
		else {
			mov(vec, pnt[i - 1].first);
			mov(vec, pnt[i - 1].first + 1);
			vec = query_seq(pnt[i - 1].first + 2, pnt[i].first) * vec;
		}
	}
	printf("%d\n", vec.a[0][0]);
	return 0;
}