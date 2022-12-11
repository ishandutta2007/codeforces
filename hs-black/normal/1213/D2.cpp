#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 200050;
int read(void) {
	int x = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}
	return x;
}
long long cnt[N], ans[N];
int a[N], len[N];
int di[N][25];
int n, m;
int main() {
	n = read(), m = read();
	for (int i = 1;i <= n; i++)
		a[i] = read();
	sort(a + 1, a + n + 1);
	for (int i = 1;i <= n; i++) {
		int tmp = 0, hh = 0;
		int p = a[i];
		while (p) {
			p >>= 1;
			len[i]++;
		}
		for (int j = len[i]-1;j >= 0; j--) {
			tmp <<= 1;
			hh++;
			if (a[i] & (1 << j))
				tmp++;
			di[i][hh] = tmp;
		}
	}
	long long k = 666666666666;
	for (int i = 0;i <= len[n]; i++) {
		memset(cnt, 0, sizeof(cnt));
		memset(ans, 0, sizeof(ans));
		for (int j = 1;j <= n; j++) {
			if (len[j] < i) continue;
			cnt[di[j][i]]++, ans[di[j][i]] += len[j] - i;
			if (cnt[di[j][i]] == m) k = min(k, ans[di[j][i]]);
		}
//		cout << i << ' ' << k << endl;
	}
	cout << k << endl;
	return 0;
}
/*
50 50
8 63 44 78 3 65 7 27 13 45 7 5 18 94 25 17 26 10 21 44 5 13 6 30 10 11 44 14 71 17 10 5 4 9 8 21 4 9 25 18 3 14 15 8 7 11 5 28 9 1

*/