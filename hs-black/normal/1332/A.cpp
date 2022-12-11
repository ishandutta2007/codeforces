#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template <typename T>
void readIn(T *a, int len) {
	for (int i = 1;i <= len; i++) read(a[i]);
}

const int N = 30005;
int T, a, b, c, d;
int x, y, l, r, u, D;

bool init(int x, int y) {
	return x >= l && x <= r && y >= u && y <= D;
}

int main() {
	read(T);
	while (T--) {
		read(a), read(b), read(c), read(d);
		read(x), read(y), read(l), read(u), read(r), read(D);
		if (!init(x, y) || !init(x - a + b, y - c + d)) puts("No");
		else {
			if (a && !init(x + 1, y) && !init(x - 1, y)) puts("No");
			else if (c && !init(x, y + 1) && !init(x, y - 1)) puts("No");
			else puts("Yes");
		}
	}
	return 0;
}