// Hydro submission #61891dc01edf93b3ad658a5a@1636376001189
#include <bits/stdc++.h>
using namespace std;

inline int read();
#define N 1000010
#define pb push_back

int n, a[N], vis[N];
vector<int> res;

int main() {
	for (int T = read(); T --; ) {
		n = read();
		for (int i = 1; i <= n; i ++) {
			a[i] = i - read(), vis[i] = 0;
		}

		int x = 1;
		while (!vis[x]) vis[x] = 1, x = a[x];
		res.clear(), res.pb(x), x = a[x];
		while (x != res[0]) res.pb(x), x = a[x];

		printf("%d\n", res.size());
		for (auto i : res) {
			printf("%d ", i);
		}
		puts("");
	}
	return 0;
}

inline int read() {
	int x = 0, f = 0; char c = 0;
	while (!isdigit(c)) f |= c == '-', c = getchar();
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return f ? -x : x;
}