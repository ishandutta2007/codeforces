// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, j;
int a[100005], b[100005];

bool moze(int k) {
	memset(b, 255, sizeof b);

	for (int i=0; i<k; i++) {
		b[2*i+1] = a[i];
	}

	for (int i=0; i<=k; i++) {
		b[2*i] = a[n-1-k+i];
	}

	int j = k;

	for (int i=0; i<n; i++) {
		if (b[i] == -1) {
			b[i] = a[j++];
		}
	}

	int z = 0;

	for (int i=1; i<n-1; i++) {
		if (b[i] < b[i-1] && b[i] < b[i+1]) {
			z++;
		}
	}

	return z >= k;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);

	int l = 1, r = (n-1)/2, o = 0;
	while (l <= r) {
		int m = (l+r) / 2;
		if (moze(m)) {
			o = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}

	moze(o);
	cout << o << '\n';
	for (int i=0; i<n; i++) cout << b[i] << " \n"[i == n-1];
}