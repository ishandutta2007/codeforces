#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// ja sam

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);

	basic_string<int> b;

	for (int i=0; i<n; i++) {
		while (b.size()) {
			if (a[i] > b.back() && a[i] <= b.back() + k) {
				b.pop_back();
			} else break;
		}
		if (b.size() == 0)
			b.push_back(a[i]);
		else if (b.back() > a[i] && b.back() <= a[i] + k) {
			//
		} else {
			b.push_back(a[i]);
		}
	}

	cout << b.size() << '\n';
}