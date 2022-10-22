#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int  x = 0, f = 1, c = getchar();
	for (;!isdigit(c); c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int N = 200005;
int n, m;
char s[N];
struct H {int a, b;};
H h[N][26], pw[N];
const int mul1 = 233, mod1 = 998244353;
const int mul2 = 19260817, mod2 = 1000000007;
vector <H> cal(int x, int l) {
	vector <H> ans;
	for (int i = 0; i < 26; ++ i) {
		H a = (H) {};
		a.a = (h[x + l][i].a - 1LL * h[x][i].a * pw[l].a % mod1 + mod1) % mod1;
		a.b = (h[x + l][i].b - 1LL * h[x][i].b * pw[l].b % mod2 + mod2) % mod2;
		ans.push_back(a);
	}
	sort(ans.begin(), ans.end(), [&] (H a, H b) {
		if (a.a != b.a) return a.a < b.a;
		return a.b < b.b;
	});
	return ans;
}
int main() {
	n = read(), m = read();
	scanf("%s", s);
	pw[0].a = pw[0].b = 1;
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < 26; ++ j) {
			h[i + 1][j].a = 1LL * h[i][j].a * mul1 % mod1;
			h[i + 1][j].b = 1LL * h[i][j].b * mul2 % mod2;
		}
		h[i + 1][s[i] - 'a'].a = (h[i + 1][s[i] - 'a'].a + 1) % mod1;
		h[i + 1][s[i] - 'a'].b = (h[i + 1][s[i] - 'a'].b + 1) % mod2;
		pw[i + 1].a = 1LL * pw[i].a * mul1 % mod1;
		pw[i + 1].b = 1LL * pw[i].b * mul2 % mod2;
	}
	for (; m --; ) {
		int x = read() - 1, y = read() - 1, l = read();
		vector <H> a = cal(x, l), b = cal(y, l);
		bool ok = 1;
		for (int i = 0; i < 26; ++ i) {
			if (a[i].a != b[i].a || a[i].b != b[i].b) ok = 0;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}