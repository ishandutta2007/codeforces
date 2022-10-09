#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, N;
int a[1 << 20], b[1 << 20], c[1 << 20];
ll invs[21], noninvs[21];

void mergesort(int* b, int N, int lvl, ll* rez) {
	if (N == 1)
		return;

	const int H = N >> 1;
	
	mergesort(b  , H, lvl-1, rez);
	mergesort(b+H, H, lvl-1, rez);

	int i = 0, j = H, k = 0;
	ll z = 0;
	while (i < H || j < N) {
		bool prvi;
		if (i == H)
			prvi = false;
		else if (j == N)
			prvi = true;
		else
			prvi = b[i] <= b[j];

		if (prvi) {
			c[k++] = b[i++];
		} else {
			z += H-i;
			c[k++] = b[j++];
		}
	}
	copy(c, c+N, b);
	rez[lvl] += z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	N = 1 << n;
	for (int i=0; i<N; i++)
		cin >> a[i];
	copy(a, a+N, b);
	mergesort(b, N, n, invs);
	copy(a, a+N, b);
	reverse(b, b+N);
	mergesort(b, N, n, noninvs);

	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		for (int i=0; i<=x; i++)
			swap(invs[i], noninvs[i]);
		cout << accumulate(invs, invs+n+1, 0ll) << '\n';
	}
}