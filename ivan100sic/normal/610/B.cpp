#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	int l = 2e9;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		l = min(l, a[i]);
	}
	basic_string<int> b;
	for (int i=0; i<n; i++) {
		if (a[i] == l) {
			b += i;
		}
	}
	int d = 0;
	for (int i=0; i<(int)b.size(); i++) {
		d = max(d, (b[(i+1)%b.size()] - b[i] - 1 + n) % n);
	}
	cout << 1ll*l*n + d << '\n';
}