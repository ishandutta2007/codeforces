#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 10, P = 1e9 + 7;
int n, lef, rig, s0, s1, s2; ll f[3][maxn];

int main() {
	scanf("%d %d %d", &n, &lef, &rig);
	s0 = rig / 3 - (lef - 1) / 3;
	s1 = (rig + 1) / 3 - lef / 3;
	s2 = (rig + 2) / 3 - (lef + 1) / 3;
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		f[0][i] = (s0 * f[0][i - 1] + s2 * f[1][i - 1] + s1 * f[2][i - 1]) % P;
		f[1][i] = (s1 * f[0][i - 1] + s0 * f[1][i - 1] + s2 * f[2][i - 1]) % P;
		f[2][i] = (s2 * f[0][i - 1] + s1 * f[1][i - 1] + s0 * f[2][i - 1]) % P;
	}
	printf("%I64d", f[0][n]);
	return 0;
}