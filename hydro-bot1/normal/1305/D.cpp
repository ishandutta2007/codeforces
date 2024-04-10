// Hydro submission #62596dbd37de167dd82c2647@1650027979443
#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0, f = 0; char c = 0;
	while (!isdigit(c)) f |= c == '-', c = getchar();
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
	return f ? -x : x;
}

#define N 1010

int n, deg[N];
vector<int> e[N];
queue<int> lef;

void update(int x) {
	for (auto y : e[x]) {
		if (-- deg[y] == 1) lef.emplace(y);
	}
}

int main() {
	n = read();
	for (int i = 1; i < n; i ++) {
		int x = read(), y = read();
		deg[x] ++, deg[y] ++;
		e[x].emplace_back(y);
		e[y].emplace_back(x);
	}
	for (int i = 1; i <= n; i ++) {
		if (deg[i] == 1) lef.emplace(i);
	}
	for (int i = 1; 2 * i <= n; i ++) {
		int x = lef.front(); lef.pop();
		int y = lef.front(); lef.pop();
		printf("? %d %d\n", x, y), fflush(stdout);
		int lca = read();
		if (lca == x) {
			return printf("! %d\n", x), 0;
		}
		if (lca == y) {
			return printf("! %d\n", y), 0;
		}
		update(x), update(y);
	}
	printf("! %d\n", lef.front());
	return 0;
}