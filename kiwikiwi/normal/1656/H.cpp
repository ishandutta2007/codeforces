#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;
#define maxN 1111

int n;
i128 r128() {
	static char s[100];
	scanf("%s", s);
	int m = strlen(s);
	i128 x = 0;
	for (int i = 0; i < m; i++) x = x * 10 + s[i] - '0';
	return x;
}
void p128(i128 x) {
	if (x == 0) return;
	else {
		p128(x/10);
		printf("%d", int(x%10));
	}
}

i128 ctz(i128 x) {
    if (u64(x) == 0)
        return __builtin_ctzll(u64(x >> 64)) + 64;
    else
        return __builtin_ctzll(u64(x));
}

i128 gcd(i128 a, i128 b) {
    if (b == 0)
        return a;

    int shift = ctz(a | b);
    b >>= ctz(b);

    while (a) {
        a >>= ctz(a);

        if (a < b)
            swap(a, b);

        a -= b;
    }

    return b << shift;
}
struct array {
	int n;
	i128 a[maxN], val[maxN], gval[maxN][maxN];
	bool inq[maxN], del[maxN];
	void read() {
		for (int i = 0; i < n; i++) {
			a[i] = r128();
			del[i] = false;
			inq[i] = false;
		}
		for (int i = 0; i < n; i++) {
			gval[i][i] = a[i];
			for (int j = 0; j < i; j++)
				gval[i][j] = gval[j][i] = gcd(a[i], a[j]);
			i128 plcm = 1;
			for (int j = 0; j < i; j++) {
				plcm = plcm / gcd(plcm, gval[j][i]) * gval[j][i];
				if (plcm == a[i]) break;
			}
			val[i] = a[i] / plcm;
		}
	}
	bool check(i128 x) {
		for (int i = 0; i < n; i++) {
			i128 d = gcd(x, val[i]);
			x /= d;
			if (x == 1) return true;
		}
		return false;
	}
	pair<i128, i128> remove(int id) {
		del[id] = true;
		i128 plcm = 1;
		for (int i = 0; i < n; i++) if (!del[i]) {
			plcm = plcm / gcd(plcm, gval[id][i]) * gval[id][i];
			if (plcm == a[id]) break;
		}
		i128 prem = a[id] / plcm;
		i128 phigh = 1, pval = a[id];
		for (int i = 0; i < 125; i++) {
			i128 d = gcd(prem, pval);
			if (d == 1) break;
			pval /= d;
			phigh *= d;
		}
		return {phigh, phigh / prem};
	}
	bool test(int id, pair<i128, i128> v) {
		i128 d = gcd(a[id], v.first);
		if (v.second % d != 0) return true;
		else return false;
	}
}a, b;
void solve() {
	scanf("%d%d", &a.n, &b.n);
	a.read();
	b.read();
	queue<pair<int,int>> q;
	for (int i = 0; i < a.n; i++) 
		if (!b.check(a.a[i])) {
			a.inq[i] = true;
			q.push({i, 0});
		}
	for (int i = 0; i < b.n; i++) 
		if (!a.check(b.a[i])) {
			b.inq[i] = true;
			q.push({i, 1});
		}
	while (!q.empty()) {
		auto p = q.front(); q.pop();
		if (p.second == 0) {
			auto r = a.remove(p.first);
			for (int i = 0; i < b.n; i++) if (!b.inq[i] && b.test(i, r)) {
				b.inq[i] = true;
				q.push({i, 1});
			}
		} else {
			auto r = b.remove(p.first);
			for (int i = 0; i < a.n; i++) if (!a.inq[i] && a.test(i, r)) {
				a.inq[i] = true;
				q.push({i, 0});
			}
		}
	}
	vector<i128> ans1, ans2;
	for (int i = 0; i < a.n; i++) if (!a.del[i]) ans1.push_back(a.a[i]);
	for (int i = 0; i < b.n; i++) if (!b.del[i]) ans2.push_back(b.a[i]);
	if (ans1.empty()||ans2.empty()) {
		puts("NO");
	} else {
		puts("YES");
		printf("%d %d\n",(int)ans1.size(), (int)ans2.size());
		for (auto x : ans1) {
			p128(x); putchar(' ');
		}
		puts("");
		for (auto x : ans2) {
			p128(x); putchar(' ');
		}
		puts("");
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++) {
		solve();
	}
}