#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x % y);
}

const int N = 789;
int n, a[N];
bool valid[N][N], val[N][N], var[N][N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) valid[i][j] = gcd(a[i], a[j]) != 1;
	}
	for (int d = 0; d < n; d++) {
		for (int l = 1; l + d <= n; l++) {
			int r = l + d;
			for (int mid = l; mid <= r; mid++) {
				bool v = ((l <= mid - 1) ? var[l][mid - 1] : 1) & ((mid + 1 <= r) ? val[mid + 1][r] : 1);
				if (!v) continue;
				if (valid[mid][l - 1]) val[l][r] = 1;
				if (valid[mid][r + 1]) var[l][r] = 1;
			}
		}
	}
	for (int mid = 1; mid <= n; mid++) {
		if (((1 <= mid - 1) ? var[1][mid - 1] : 1) & ((mid + 1 <= n) ? val[mid + 1][n] : 1)) {
			puts("Yes");
			return 0;
		}
	}
	puts("No");
}