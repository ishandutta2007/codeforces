#include<iostream>
#include<cstdio>
#include<cstring>
#include<bitset>
using namespace std;
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
const int N = 1000500;
int vis[N], to[N], n;
int k, tot, ansx, ansn;
int num[N], w[N];
bitset<N> dp;
int val[N], tot1;
int main() {
	n = read(), k = read();
	for (int i = 1;i <= n; i++) to[i] = read();
	for (int i = 1;i <= n; i++) {
		int index = i, cnt = 0;
		while (!vis[index]) {
			vis[index] = 1;
			index = to[index];
			cnt++;
		}
		if (!cnt) continue;
		if (num[cnt]) num[cnt]++;
		else num[cnt]++, w[++tot] = cnt;
	}
	for (int i = 1;i <= tot; i++) ansx += num[w[i]] * (w[i] / 2);
	if (ansx >= k) ansx = 2 * k;
	else ansx += k;
	ansx = min(ansx, n);
	for (int i = 1;i <= tot; i++) {
		for (int j = 1;j <= num[w[i]]; j <<= 1) {
				val[++tot1] = j * w[i];
				num[w[i]] -= j;
		}
		if (num[w[i]] > 0) val[++tot1] = num[w[i]] * w[i];
	}
	dp.set(0);
	for (int i = 1;i <= tot1; i++)
	dp |= (dp << val[i]);
	if (dp.test(k)) ansn = k;
	else ansn = k + 1;
	cout << ansn << ' ' << ansx << endl;
	return 0;
}