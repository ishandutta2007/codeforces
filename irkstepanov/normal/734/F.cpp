#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool bit(ll mask, int pos)
{
	return (mask >> pos) & 1;
}

const int rmax = 31;

int main()
{

	int n;
	cin >> n;

	vector<ll> b(n), c(n);
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}

	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += b[i] + c[i];
	}

	if (sum % (ll(2) * n)) {
		cout << "-1\n";
		return 0;
	}

	sum /= ll(2) * n;

	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = (b[i] + c[i] - sum) / n;
	}

	for (int r = rmax - 1; r >= 0; --r) {
		int k = 0;
		for (int i = 0; i < n; ++i) {
			k += int(bit(a[i], r));
		}
		for (int i = 0; i < n; ++i) {
			if (bit(a[i], r)) {
				c[i] -= ll(n) * (1LL << r);
				b[i] -= ll(k) * (1LL << r);
			} else {
				c[i] -= ll(k) * (1LL << r);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (b[i] || c[i]) {
			cout << "-1\n";
			return 0;
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << "\n";

}