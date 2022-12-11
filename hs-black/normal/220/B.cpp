#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 100500;
int n, m, siz;
struct node{
	int l, r, num;
	bool operator < (const node &i) const {
		if (l / siz == i.l / siz) return r < i.r;
		return l / siz < i.l / siz;
	}
}q[N];
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
int ans[N], cnt[N], a[N];
int main() {
	n = read(), m = read();
	for (int i = 1;i <= n; i++) a[i] = read();
	for (int i = 1;i <= m; i++) {
		int l = read(), r = read();
		q[i] = (node){l, r, i};
	}
	siz = sqrt(n);
	sort(q + 1,q + m + 1);
	int tmp = 0, l = 0, r = 0;
	cnt[0] = -1;
	for (int i = 1;i <= m; i++) {
		while (l < q[i].l) {
			if (a[l] > n) continue;
			cnt[a[l]]--;
			if (cnt[a[l]] == a[l]) tmp++;
			if (cnt[a[l]] == a[l] - 1) tmp--;
			l++;
		}
		while (l > q[i].l) {
			l--;
			if (a[l] > n) continue;
			cnt[a[l]]++;
			if (cnt[a[l]] == a[l]) tmp++;
			if (cnt[a[l]] == a[l] + 1) tmp--;
		}
		while (r < q[i].r) {
			r++;
			if (a[r] > n) continue;
			cnt[a[r]]++;
			if (cnt[a[r]] == a[r]) tmp++;
			if (cnt[a[r]] == a[r] + 1) tmp--;
		}
		while (r > q[i].r) {
			cnt[a[r]]--;
			if (a[r] > n) continue;
			if (cnt[a[r]] == a[r]) tmp++;
			if (cnt[a[r]] == a[r] - 1) tmp--;
			r--;
		}
		ans[q[i].num] = tmp;
	}
	for (int i = 1;i <= m; i++) printf ("%d\n", ans[i]);
	return 0;
}