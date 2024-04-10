#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
	f = 0; _T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 1e5 + 5;

int a[N], b[N], vis[N];
int T, n, minn, len;

int main() {
	read(T);
	while (T--) {
		read(n); minn = 2e9; len = 0;
		for (int i = 1; i <= n; i++) read(a[i]), minn = min(minn, a[i]), vis[i] = 0;
		for (int i = 1; i <= n; i++) if (a[i] % minn == 0) vis[i] = 1, b[++len] = a[i];
		sort(b + 1, b + len + 1);
		int now = 1;
		for (int i = 1; i <= n; i++) if (vis[i]) a[i] = b[now], ++now;
		bool ok = 1;
		for (int i = 2; i <= n; i++) if (a[i - 1] > a[i]) ok = 0;
		if (ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}