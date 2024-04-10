// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const int maxn = 1 << 20;
int b[2*maxn];

void add(int x, int v) {
	x += maxn;
	while (x > 0) {
		b[x] += v;
		x >>= 1;
	}
}

int ordstat(int x, int k) {
	if (x >= maxn)
		return x - maxn;
	if (b[2*x] > k)
		return ordstat(2*x, k);
	else
		return ordstat(2*x+1, k-b[2*x]);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n, q;
	cin >> n >> q;

	int sz = n;

	while (n--) {
		int x;
		cin >> x;
		add(x, 1);
	}

	while (q--) {
		int k;
		cin >> k;
		if (k > 0) {
			add(k, 1);
			sz++;
		} else {
			sz--;
			k = abs(k);
			k--;
			int x = ordstat(1, k);
			add(x, -1);
		}
	}

	if (sz == 0)
		cout << "0\n";
	else
		cout << ordstat(1, 0) << '\n';
}