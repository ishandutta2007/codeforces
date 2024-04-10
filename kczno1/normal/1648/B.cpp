#include <bits/stdc++.h>
using namespace std;

typedef long long s64;

const int N = 1e6 + 5;
bool ap[N];
int nex[N];

bool check() {
	int n, c;
	cin >> n >> c;
	for (int i = 1; i <= c + 1; ++i) ap[i] = 0;
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		ap[x] = 1;
	}
	nex[c + 1] = c + 1;
	for (int i = c; i; --i) nex[i] = ap[i] ? i : nex[i + 1];
	for (int x = 1; x <= c; ++x)
		if (ap[x]) {
			for (int y = x; y <= c; y += x) {
				int z = min(y + x, c + 1);
				if (nex[y] < z && !ap[y / x]) return 0;
			}
		}
	return 1;
}

int main() {
#ifdef kcz
	freopen("1.in", "r", stdin); //freopen("1.out","w",stdout);
#endif
	int tt;
	cin >> tt;
	while (tt--) {
		puts(check() ? "Yes" : "No");
	}
}