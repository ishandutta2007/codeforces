#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n, k, a, z=0;
	cin >> n >> k;
	vector<int> x(n), c(n);
	for (int i=0; i<n; i++)
		cin >> x[i];
	cin >> a;
	for (int i=0; i<n; i++)
		cin >> c[i];
	multiset<int> ms;
	for (int i=0; i<n; i++) {
		ms.insert(c[i]);
		while (k < x[i]) {
			if (ms.size() == 0) {
				cout << "-1\n";
				return 0;
			} else {
				k += a;
				z += *ms.begin();
				ms.erase(ms.begin());
			}
		}
	}
	cout << z << '\n';
}