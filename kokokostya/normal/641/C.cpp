#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

int a [int(1e6)];

int main() {
	ios_base::sync_with_stdio(false);
	int n, q;
	scanf("%d%d", &n, &q);
	long long now1 = 0;
	long long now2 = 1;
	int x, t;
	for (int i = 0; i < q; i++) {
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d", &x);
			now1 += x;
			now2 += x;
		}
		else {
			if (now1 % 2 != 0) {
				now1--;
				now2++;
			}
			else {
				now1++;
				now2--;
			}
		}
	}
	now1 %= n;
	if (now1 < 0)
		now1 += n;
	now2 %= n;
	if (now2 < 0)
		now2 += n;
	for (int i = 0; i < n / 2; i++) {
		a[now1] = 2 * i;
		now1 += 2;
		if (now1 >= n)
			now1 -= n;
	}
	for (int i = 0; i < n / 2; i++) {
		a[now2] = 2 * i + 1;
		now2 += 2;
		if (now2 >= n)
			now2 -= n;
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] + 1 << ' ';
	}
	return 0;
}