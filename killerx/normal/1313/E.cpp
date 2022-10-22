#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mul[2] = {233, 19260817};
const int mod[2] = {998244353, 1000000007};

const int N = 1e6 + 5;

char temp[N];

struct String {
	string s;
	vector <int> h[2], pw[2];
	
	void read() {
		scanf("%s", temp);
		s = temp;
		build_hash();
	}
	
	void build_hash() {
		for (int k = 0; k < 2; ++ k) {
			pw[k].resize(s.size() + 1);
			pw[k][0] = 1;
			for (int i = 0; i < s.size(); ++ i)
				pw[k][i + 1] = 1LL * pw[k][i] * mul[k] % mod[k];
			h[k].resize(s.size() + 1);
			for (int i = 0; i < s.size(); ++ i)
				h[k][i + 1] = (1LL * h[k][i] * mul[k] % mod[k] + s[i]) % mod[k];
		}
	}
	
	int get(int l, int r, int k) {
		return (h[k][r] + mod[k] - 1LL * h[k][l] * pw[k][r - l] % mod[k]) % mod[k];
	}
};

int n, m;
String a, b, s;
int len_a[N], len_b[N];

struct BIT {
	ll sum[N];
	BIT() {memset(sum, 0, sizeof(sum));}
	void upd(int x, ll v) {for (++ x; x < N; x += x & -x) sum[x] += v;}
	ll qry(int x) {ll ans = 0; for (++ x; x; x -= x & -x) ans += sum[x]; return ans;}
	ll qry(int l, int r) {return qry(r) - qry(l - 1);}
};

BIT B0, B1;
ll ans;

int main() {
	scanf("%d %d", &n, &m);
	a.read(); b.read(); s.read();
	for (int i = 0; i < n; ++ i) {
		int lb = 0, rb = min(n - i, m - 1);
		while (lb < rb) {
			int md = lb + rb + 1 >> 1;
			if (a.get(i, i + md, 0) == s.get(0, md, 0) &&
				a.get(i, i + md, 1) == s.get(0, md, 1))
				lb = md;
			else
				rb = md - 1;
		}
		len_a[i] = lb;
	}
	for (int i = 0; i < n; ++ i) {
		int lb = 0, rb = min(i + 1, m - 1);
		while (lb < rb) {
			int md = lb + rb + 1 >> 1;
			if (b.get(i + 1 - md, i + 1, 0) == s.get(m - md, m, 0) &&
				b.get(i + 1 - md, i + 1, 1) == s.get(m - md, m, 1))
				lb = md;
			else
				rb = md - 1;
		}
		len_b[i] = lb;
	}
	for (int i = n - 1; ~i; -- i) {
		B0.upd(len_b[i], 1), B1.upd(len_b[i], len_b[i]);
		if (i + m - 1 < n) B0.upd(len_b[i + m - 1], -1), B1.upd(len_b[i + m - 1], -len_b[i + m - 1]);
		if (len_a[i]) ans += B1.qry(m - len_a[i], m) - B0.qry(m - len_a[i], m) * (m - len_a[i] - 1);
	}
	printf("%lld\n", ans);
	return 0;
}