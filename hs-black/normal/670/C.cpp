#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int read() {
	int x = 0;
	char c = getchar();
	while (!isdigit(c)) x = getchar();
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c -'0';
		c = getchar();
	}
	return x;
}

const int N = 200005;
int a[N<<3];

inline int ask(int x, int k) {
	return lower_bound(a + 1,a + k + 1, x) - a;
}

int b[N], c[N], cnt[N<<3], r[N];

int main() {
	int n = read();
	int t = 0;
	for (int i = 1;i <= n; i++) a[++t] = r[i] = read();
	int m = read();
	for (int i = 1;i <= m; i++) b[i] = a[++t] = read();
	for (int i = 1;i <= m; i++) c[i] = a[++t] = read();
	sort(a + 1, a + t + 1);
	int k = unique(a + 1, a + t + 1) - a - 1;
	for (int i = 1;i <= n; i++) cnt[ask(r[i], k)]++;
	int maxb = 0, maxc = 0, l = 1;
	for (int i = 1;i <= m; i++) {
		int x = ask(b[i], k), y = ask(c[i], k);
		if (cnt[x] > maxb)
			maxb = cnt[x], maxc = cnt[y], l = i;
		else if (cnt[x] == maxb && cnt[y] > maxc)
			maxc = cnt[y], l = i;
	}
	cout << l << endl;
	return 0;
}