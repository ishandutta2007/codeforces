// Hydro submission #6260f581255d14008c2388bf@1650521474421
#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0, f = 0; char c = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
    return f ? -x : x;
}

#define P 32768

int n, a[P + 5], b[P + 5];
queue<int> q;

void Add(int x, int y) {
	if (a[y] == -1) {
		a[y] = a[x] + 1;
		q.push(y);
	}
}

void bfs() {
	q.push(0);
	memset(a, -1, sizeof a);
	a[0] = 0;
	while (q.size()) {
		int x = q.front(); q.pop();
		Add(x, (x - 1 + P) % P);
		if (x % 2 == 0) {
			Add(x, x / 2);
			Add(x, ((x + P) / 2) % P);
		}
	}
}

signed main() {
	bfs();
	n = read();
	for (int i = 1; i <= n; i ++) {
		b[i] = read();
	}
	for (int i = 1; i <= n; i ++) {
		printf("%d ", a[b[i]]);
	}
	return 0;
}