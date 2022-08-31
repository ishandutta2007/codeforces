#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 998244353;
const int maxN = 2234;

int n, t, x[maxN], y[maxN];
vector<int> row, col;

i64 inv[maxN], invfac[maxN];

void init(int deg) {
	invfac[0] = 1;
	invfac[1] = 1;
	inv[1] = 1;
	for (int i = 2; i <= deg; i++) {
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
		invfac[i] = invfac[i - 1] * inv[i] % mod;
	}
}

i64 interpol(i64 *p, int deg, i64 x) {
	i64 mul1[10], mul2[10];
	mul1[0] = 1;
	mul2[0] = 1;
	for (int i = 0; i <= deg; i++) {
		mul1[i + 1] = mul1[i] * (x - i) % mod;
		mul2[i + 1] = mul2[i] * (x - deg + i) % mod;
	}

	i64 ans = 0;
	for (int i = 0; i <= deg; i++) {
		i64 t = invfac[i] * invfac[deg - i] % mod * mul1[i] % mod * mul2[deg - i] % mod * p[i] % mod;
		if ((deg - i) & 1) ans = ans - t;
		else ans = ans + t;
	}
	ans = ans % mod;
	if (ans < 0) ans += mod;
	return ans;

}

vector<vector<int>> seg[123];
int cnt[123];
i64 len[123];
i64 solvet(int t) {
	vector<int> row, col;
	for (int i = 0; i < n; i++) {
		row.push_back(x[i] - t);
		row.push_back(x[i] + t + 1);
		col.push_back(y[i] - t);
		col.push_back(y[i] + t + 1);
	}
	sort(row.begin(), row.end());
	row.erase(unique(row.begin(), row.end()), row.end());
	sort(col.begin(), col.end());
	col.erase(unique(col.begin(), col.end()), col.end());
	int r = row.size(), c = col.size();
	for (int i = 0; i < r; i++) seg[i].clear();
	for (int j = 0; j + 1 < c; j++) {
		cnt[j] = 0;
		len[j] = col[j + 1] - col[j];
	}
	for (int i = 0; i < n; i++) {
		int px = lower_bound(row.begin(), row.end(), x[i] - t) - row.begin();
		int qx = lower_bound(row.begin(), row.end(), x[i] + t + 1) - row.begin();
		int py = lower_bound(col.begin(), col.end(), y[i] - t) - col.begin();
		int qy = lower_bound(col.begin(), col.end(), y[i] + t + 1) - col.begin();
		seg[px].push_back(vector<int> {py, qy, 1});
		seg[qx].push_back(vector<int> {py, qy, -1});
	}
	i64 ans = 0;
	for (int i = 0; i + 1 < r; i++) {
		for (auto p : seg[i]) {
			for (int j = p[0]; j < p[1]; j++) {
				cnt[j] += p[2];
			}
		}
		i64 rlen = row[i + 1] - row[i];
		for (int j = 0; j + 1 < c; j++)
			if (cnt[j] > 0) ans = ans + len[j] * rlen;
	}
	return ans;
}


vector<int> v;

i64 solve(int t1, int t2) {
	i64 d[10];
	for (int i = 0; i <= 3; i++) {
		d[i] = solvet(t1 + i) % mod;
	}
	for (int i = 1; i <= 3; i++) d[i] = (d[i - 1] + d[i]) % mod;
	return interpol(d, 3, t2 - t1);
}

int main() {
	init(100);
	scanf("%d%d", &n, &t);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x[i], &y[i]);
	}
	v.push_back(0);
	v.push_back(t + 1);
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
			int d = (max(abs(x[i] - x[j]), abs(y[i] - y[j])) - 1) / 2;
			if (d < t) v.push_back(d);
		}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	i64 ans = (solvet(t) % mod * (t + 1)) % mod;
	for (int i = 0; i + 1 < v.size(); i++) {
		ans = (ans - solve(v[i], v[i + 1] - 1)) % mod;
	}
	if (ans < 0) ans += mod;
	printf("%lld\n", ans);
}