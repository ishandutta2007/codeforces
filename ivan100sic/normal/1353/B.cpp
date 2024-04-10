// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

void rd(vector<int>& x) {
	for (int& y : x)
		cin >> y;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n), b(n);
		rd(a);
		rd(b);
		while (k--) {
			int i = min_element(begin(a), end(a)) - a.begin();
			int j = max_element(begin(b), end(b)) - b.begin();
			if (a[i] < b[j]) {
				swap(a[i], b[j]);
			} else {
				break;
			}
		}

		cout << accumulate(begin(a), end(a), 0) << '\n';
	}
}