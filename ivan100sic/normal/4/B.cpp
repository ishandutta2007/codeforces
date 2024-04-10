#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, s, sl, sr;
int l[33], r[33];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;
	for (int i=0; i<n; i++) {
		cin >> l[i] >> r[i];
		sl += l[i];
		sr += r[i];
	}

	if (s < sl || s > sr) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	s -= sl;
	for (int i=0; i<n; i++) {
		int x = min(s, r[i]-l[i]);
		cout << l[i] + x << " \n"[i == n-1];
		s -= x;
	}
}