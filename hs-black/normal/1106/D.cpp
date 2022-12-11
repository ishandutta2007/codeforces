#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N = 100005;
int h[N], to[N<<1];
int ne[N<<1], n, m, tot;
int read(void) {
	int x = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x;
}
inline void add(int x,int y) {
	ne[++tot] = h[x];
	h[x] = tot, to[tot] = y;
}

#include<queue>
priority_queue<int> q;

int v[N];

int main() {
	n = read(), m = read();
	for (int i = 1;i <= m; i++) {
		int x = read(), y = read();
		add(x, y);
		add(y, x);
	}
	q.push(-1);
	while (!q.empty()) {
		int x = -q.top(); q.pop();
		if (v[x]) continue;
		v[x] = 1;
		printf ("%d ", x);
		for (int i = h[x]; i; i = ne[i]) {
			int y = to[i];
			if (v[y]) continue;
			q.push(-y);
		}
	}
	return 0;
}