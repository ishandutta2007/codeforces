#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int l[1005], r[1005];
int p[1005], q[1005], a[1005];
int L[1005], R[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> l[i];
	for (int i=1; i<=n; i++)
		cin >> r[i];

	copy(l+1, l+n+1, p+1);
	copy(r+1, r+n+1, q+1);

	for (int i=n; i>=1; i--) {
		basic_string<int> pos;
		for (int j=1; j<=n; j++)
			if (!a[j] && !p[j] && !q[j]) {
				pos += j;
				a[j] = i;
			}
		for (int k=1; k<=n; k++) {
			auto it = lower_bound(pos.begin(), pos.end(), k);
			if (it != pos.end() && *it == k) {
				continue;
			}
			p[k] -= it - pos.begin();
			q[k] -= pos.end() - it;
		}
	}

	for (int i=1; i<=n; i++) {
		for (int j=1; j<i; j++)
			if (a[j] > a[i])
				L[i]++;
		for (int j=i+1; j<=n; j++)
			if (a[j] > a[i])
				R[i]++;
	}

	for (int i=1; i<=n; i++) {
		if (l[i] != L[i] || r[i] != R[i]) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
	for (int i=1; i<=n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}