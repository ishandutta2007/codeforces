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

	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x : a)
		cin >> x;
	int y = *min_element(a.begin(), a.end());
	int l = -1, z = 123123123;
	for (int i=0; i<n; i++) {
		if (a[i] == y) {
			if (l == -1) {
				l = i;
			} else {
				z = min(z, i-l);
				l = i;
			}
		}
	}
	cout << z << '\n';
}