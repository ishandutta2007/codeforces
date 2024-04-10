#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int n, m;
ll k;

int main() {
	scanf("%d %d %lld", &n, &m, &k);
	if (k < n) {
		printf("%lld %d\n", k + 1, 1);
	} else {
		k -= n;
		int tms = k / (m - 1);
		int pos = k % (m - 1);
		int x = n - tms;
		int y = tms & 1 ? m - pos : 2 + pos;
		printf("%d %d\n", x, y);
	}
	return 0;
}