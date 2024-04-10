#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

basic_string<int> lucky;

void gen_lucky() {
	for (int l=1; l<=9; l++) {
		for (int mask=0; mask<(1<<l); mask++) {
			int x = 0;
			for (int j=0; j<l; j++) {
				x *= 10;
				if (mask & (1 << j))
					x += 4;
				else
					x += 7;
			}
			lucky += x;
		}
	}

	lucky += -1000000007;
	lucky += 1000000007;

	sort(lucky.begin(), lucky.end());
}

int pl, pr, ql, qr, k;

int presek(int a, int b, int c, int d) {
	a = max(a, c);
	b = min(b, d);
	return max(0, b-a+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> pl >> pr >> ql >> qr >> k;

	ll cnt = 0;

	gen_lucky();

	for (int i=1; i+k<(int)lucky.size(); i++) {
		int al = lucky[i-1] + 1;
		int ar = lucky[i];
		int bl = lucky[i+k-1];
		int br = lucky[i+k] - 1;

		cnt += presek(al, ar, pl, pr) * 1ll * presek(bl, br, ql, qr);
		cnt += presek(al, ar, ql, qr) * 1ll * presek(bl, br, pl, pr);

		if (ar == bl)
			cnt -= presek(ar, ar, pl, pr) && presek(ar, ar, ql, qr);
	}

	cout << setprecision(20) << fixed << ld(cnt)/(pr-pl+1)/(qr-ql+1) << '\n';
}