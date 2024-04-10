#include <bits/stdc++.h>
using namespace std;

int n, m, h;
int wys[100];

int main () {

	scanf("%d %d %d", &n, &h, &m);
	for(int i = 0; i < 100; i++) {
		wys[i] = h;
	}
	for(int i = 0; i < m; i++) {
		int l, r, x;
		scanf("%d %d %d", &l, &r, &x);
		for(int j = l; j <= r; j++) {
			wys[j] = min(wys[j], x);
		}
	}

	int result = 0;
	for(int i = 1; i <= n; i++) {
		result += wys[i] * wys[i];
	}

	printf("%d\n", result);

	return 0;
}