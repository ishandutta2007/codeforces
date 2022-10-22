#include <bits/stdc++.h>
using namespace std;

int main() {
	string a[3];
	string A, B, C;
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	A = a[0], B = a[1], C = a[2];
	int ans = 2;
	if (A == B && B == C) {
		ans = 0;
	} else if (A == B || B == C) {
		ans = 1;
	}
	if (A[1] == B[1] && B[1] == C[1]) {
		ans = min(ans, (A[0] != B[0] - 1) + (B[0] != C[0] - 1));
	} else if (A[1] == B[1]) {
		ans = min(ans, 1 + (A[0] != B[0] - 1));
	} else if (B[1] == C[1]) {
		ans = min(ans, 1 + (B[0] != C[0] - 1));
	}
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 3; j++) {
			if (a[i][1] == a[j][1] && a[j][0] - a[i][0] > 0 && a[j][0] - a[i][0] < 3) {
				ans = min(ans, 1);
			}
		}
	}
	printf("%d", ans);
  return 0;
}