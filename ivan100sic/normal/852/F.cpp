#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, a, q, f, eulerf;

vector<int> prosti;
int ff[100005];

void sito() {
	for (int i = 2; i <= 100000; i++) {
		if (ff[i] == 0) {
			prosti.push_back(i);
			ff[i] = i;
			for (int j = 2*i; j <= 100000; j += i) {
				if (ff[j] == 0) {
					ff[j] = i;
				}
			}
		}
	}
}

inline int digni(int x, int b, int mod) {
	if (b == 0) {
		return 1;
	}
	if (b == 1) {
		return x % mod;
	}
	int t = digni(x, b / 2, mod);
	t = t * 1ll * t % mod;
	if (b % 2) {
		t = t * 1ll * x % mod;
	}
	return t;
}

int findeuler(int x) {
	int prod = 1;
	for (int p : prosti) {
		if (x % p == 0) {
			prod *= p - 1;
			x /= p;
			while (x % p == 0) {
				prod *= p;
				x /= p;
			}
		}
	}
	if (x > 1) {
		prod *= x - 1;
	}
	return prod;
}

int find_mult_order(int a, int q) {
	const int eulerf = findeuler(q);
	int resto = eulerf;
	int f = eulerf;

	for (int p : prosti) {
		if (eulerf % p == 0) {
			if (digni(a, p, q) == 1) {
				f = min(f, p);
			}
			while (resto % p == 0) {
				resto /= p;
			}
		}
	}

	if (resto > 1) {
		if (digni(a, resto, q) == 1) {
			f = min(f, resto);
		}
	}

	return f;
}

void test() {
	printf("%d\n", findeuler(1000000006));
	for (int i = 2; i <= 10; i++) {
		printf("%d\n", find_mult_order(i, 1000000007));
	}
}

int main() {
	sito();

	// test();

	scanf("%d%d%d%d", &n, &m, &a, &q);

	f = find_mult_order(a, q);

	// fprintf(stderr, "f = %d\n", f);

	vector<int> bik(m+1, 0);
	vector<int> prebik(n, 0);
	
	bik[0] = 1;
	for (int i = 1; i <= m; i++) {
		bik[i] = bik[i - 1] * 1ll * (m - i + 1) % f * digni(i, f - 2, f) % f;
	}

	prebik[0] = bik[0];
	for (int i = 1; i < n; i++) {
		if (i <= m) {
			prebik[i] = (prebik[i - 1] + bik[i]) % f;
		} else {
			prebik[i] = prebik[i - 1];
		}
	}

	for (int i = n-1; i >= 0; i--) {
		printf("%d ", digni(a, prebik[i], q));
	}

	{
		int _;
		scanf("%d", &_);
	}
}