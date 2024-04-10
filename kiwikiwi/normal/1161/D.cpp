#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define maxN 22345

const int P = 998244353;

int f[maxN], u[maxN], v[maxN], w[maxN];
int n, z, ida[maxN], idb[maxN];
char s[maxN];

int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}

int calc() {
	for (int i = 0; i <= 2 * z + 1; i++) {
		f[i] = i;
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') continue;
		int u = ida[i];
		int v = idb[i];
		int w = s[i] - '0';
		f[find(2 * u)] = find(2 * v + w);
		f[find(2 * u + 1)] = find(2 * v + 1 - w);
	}
	f[find(2 * idb[0])] = find(2 * 0 + 1);
	f[find(2 * idb[0] + 1)] = find(2 * 0);
	for (int i = 0; i <= z; i++)
		if (find(2 * i) == find(2 * i + 1)) return 0;
	int comp = 0;
	for (int i = 0; i <= 2 * z + 1; i++)
		if (find(i) == i)
			comp++;
	assert(comp % 2 == 0);
	int ans = 1;
	for (int i = 0; i < comp / 2 - 1; i++)
		ans = ans * 2 % P;
	return ans;
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	reverse(s, s + n);
	int ans = 0;
	for (int m = 1; m < n; m++) {
		z = 0;
		for (int i = 0; i + i < n; i++) {
			ida[i] = ida[n - 1 - i] = ++z;
		}
		memset(idb, 0, sizeof(idb));
		for (int i = 0; i + i < m; i++) {
			idb[i] = idb[m - 1 - i] = ++z;
		}
		ans = (ans + calc()) % P;
	}
	printf("%d\n", ans);
}