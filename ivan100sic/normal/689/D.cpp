#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int mx[200005][18];
int mn[200005][18];
int lg2[200005];
int n;

int getmx(int l, int r) {
	if (l == r)
		return -2012012012;
	int w = r-l;
	int i = lg2[w];
	return max(mx[l][i], mx[r-(1<<i)][i]);
}

int getmn(int l, int r) {
	if (l == r)
		return 2012012012;
	int w = r-l;
	int i = lg2[w];
	return min(mn[l][i], mn[r-(1<<i)][i]);
}

ll razlika(int l, int r) {
	return 0ll + getmx(l, r) - getmn(l, r);
}

int lbound(int x, int y, int v) {
	int l = x, r = y-1, o = y;
	while (l <= r) {
		int m = (l+r) >> 1;
		if (razlika(x, m+1) >= v) {
			o = m;
			r = m-1;
		} else {
			l = m+1;
		}
	}
	return o;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	memset(mx, 192, sizeof(mx));
	memset(mn, 63, sizeof(mn));

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> mx[i][0];
	for (int i=0; i<n; i++)
		cin >> mn[i][0];

	for (int i=2; i<=n; i++)
		lg2[i] = 1 + lg2[i >> 1];

	for (int i=1; i<18; i++) {
		for (int j=0; j<n; j++) {
			int h = 1 << (i-1);
			mx[j][i] = max(mx[j][i-1], j+h < 200005 ? mx[j+h][i-1] : mx[j][i-1]);
			mn[j][i] = min(mn[j][i-1], j+h < 200005 ? mn[j+h][i-1] : mn[j][i-1]);
		}
	}

	ll sol = 0;

	for (int l=0; l<n; l++) {
		int p = lbound(l, n, 0);
		int q = lbound(l, n, 1);
		// cerr << l << ' ' << p << ' ' << q << '\n';
		sol += q - p;
	}

	cout << sol << '\n';
}