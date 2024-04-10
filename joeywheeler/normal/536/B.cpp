#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define FO(i,a,b) for (int i = a; i < b; i++)
#define sz(v) int(v.size())

using namespace std;

char s[1000005];
int z[1000005];
int n;
int L;

void zalg() {
	int L = 0, R = 0;
	for (int i = 1; i < n; i++) {
		if (i > R) {
			L = R = i;
			while (R < n && s[R-L] == s[R]) R++;
			z[i] = R-L; R--;
		} else {
			int k = i-L;
			if (z[k] < R-i+1) z[i] = z[k];
			else {
				L = i;
				while (R < n && s[R-L] == s[R]) R++;
				z[i] = R-L; R--;
			}
		}
	}
	z[0] = n;
}

int main() {
	int o;
	scanf("%d %d", &L, &o);
	scanf(" %s", s);
	n = strlen(s);
	zalg();
	int prev = -1e9;
	long long res = 1, MOD = 1000000007;
	FO(Z,0,o) {
		int x; scanf("%d", &x);

		int l = max(prev+n,1);
		int r = x-1;
		if (l <= r) {
			for (int i = l; i <= r; i++) res = res*26%MOD;
		} else {
			// suffix starting at x must be prefix
			int p = x-prev;
			if (p < n) if (z[p] != n-p) res = 0;
		}

		prev = x;
	}
	int x = L+1;
	int l = max(prev+n,1);
	int r = x-1;
	if (l <= r) {
		for (int i = l; i <= r; i++) res = res*26%MOD;
	}

	printf("%lld\n", res);
}