#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005], b[100005];

struct stvar {
	int w, x;
};

stvar st[100005];
int ss;
ll zz;

ll resi(int l, int r) {
	zz = 0;
	ss = 0;
	ll sol = 0;
	for (int i=l; i<=r; i++) {
		int w = 1;
		while (ss > 0 && st[ss-1].x <= b[i]) {
			zz -= st[ss-1].x * 1ll * st[ss-1].w;
			w += st[ss-1].w;
			ss--;
		}
		st[ss++] = {w, b[i]};
		zz += b[i] * 1ll * w;
		sol += zz;
	}
	return sol;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;
	cin >> n >> q;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		b[i] = abs(a[i] - a[i-1]);
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << resi(l+1, r) << '\n';
	}
}