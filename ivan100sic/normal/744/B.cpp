#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int x[1005];

int main() {
	cin >> n;

	for (int i=1; i<=n; i++) {
		x[i] = 1000000000;
	}

	for (int i=0; i<10; i++) {

		vector<int> s1, s2;
		int msk = 1 << i;

		for (int j=1; j<=n; j++) {
			if (msk & j) {
				s1.push_back(j);
			} else {
				s2.push_back(j);
			}
		}

		if (s1.size() > 0) {
			cout << s1.size() << '\n';
			for (int x : s1) {
				cout << x << ' ';
			}
			cout << '\n' << flush;

			for (int j=1; j<=n; j++) {
				int y;
				cin >> y;
				if (!(msk & j)) {
					x[j] = min(x[j], y);
				}
			}
		}

		if (s2.size() > 0) {
			cout << s2.size() << '\n';
			for (int x : s2) {
				cout << x << ' ';
			}
			cout << '\n' << flush;

			for (int j=1; j<=n; j++) {
				int y;
				cin >> y;
				if (msk & j) {
					x[j] = min(x[j], y);
				}
			}
		}
	}
	cout << -1 << '\n';
	for (int i=1; i<=n; i++) {
		cout << x[i] << ' ';
	}
	cout << '\n' << flush;


}