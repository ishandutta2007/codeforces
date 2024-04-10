// Hydro submission #62761a51100a2135bc363108@1651907154291
#include <bits/stdc++.h>
using namespace std;
#define int long long

inline int read() {
	int x = 0, f = 0; char c = 0;
	while (!isdigit(c)) f |= c == '-', c = getchar();
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
	return f ? -x : x;
}

#define P 998244353
#define N 200005

int n, m, a[30][N], pw[N], iv[N];
char s[N];

int Pow(int x, int k, int r = 1) {
	for (; k; k >>= 1, x = x * x % P) {
		if (k & 1) r = r * x % P;
	}
	return r;
}

int geh(int i, int l, int r) {
	return (a[i][r] - a[i][l - 1] + P) % P * iv[l - 1] % P;
}


signed main() {
	n = read(), m = read(), scanf("%s", s + 1);
	pw[0] = iv[0] = 1;
	for (int i = 1; i < N; i ++) {
		pw[i] = pw[i - 1] * 2 % P;
		iv[i] = Pow(pw[i], P - 2);
	}
	for (char c = 'a'; c <= 'z'; c ++) {
		int i = c - 'a' + 1;
		for (int j = 1; j <= n; j ++) {
			a[i][j] = (a[i][j - 1] + (s[j] == c) * pw[j - 1]) % P;
		}
	}
	while (m --) {
		int x = read(), y = read(), len = read();
		bool flag = true;
		vector<int> vx, vy;
		for (int i = 1; i <= 26; i ++) {
			vx.emplace_back(geh(i, x, x + len - 1));
			vy.emplace_back(geh(i, y, y + len - 1));
		}
		sort(vx.begin(), vx.end());
		sort(vy.begin(), vy.end());
		for (int i = 0; i < 26; i ++) {
			if (vx[i] != vy[i]) flag = false;
		}
		flag ? puts("YES") : puts("NO");
	}
	return 0;
}