#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k;
int a[200005];

bool moze(int x) {
	int curr = k, kutije = 1;
	for (int i=x; i<=n; i++) {
		if (curr - a[i] < 0) {
			kutije++;
			curr = k - a[i];
		} else {
			curr -= a[i];
		}
	}
	return kutije <= m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	int l = 1, r = n-1, o = n;
	while (l <= r) {
		int mid = (l+r) >> 1;
		if (moze(mid)) {
			o = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << n-o+1 << '\n';
}