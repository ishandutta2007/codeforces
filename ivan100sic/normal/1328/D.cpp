// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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

	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i=0; i<n; i++)
			cin >> a[i];

		// sve ista boja?
		bool razl = false;
		for (int i=1; i<n; i++)
			if (a[i] != a[0])
				razl = true;

		if (!razl) {
			// dosta je jedna boja
			cout << "1\n";
			for (int i=0; i<n; i++)
				cout << 1 << " \n"[i == n-1];
		} else {
			int rot = 0;
			for (int i=1; i<n; i++) {
				if (a[i] != a[i-1]) {
					rotate(a.begin(), a.begin()+i, a.end());
					rot = i;
					break;
				}
			}

			// greedy namesti 2 boje
			vector<int> b(n);
			b[0] = 1;
			for (int i=1; i<n; i++) {
				if (a[i] != a[i-1])
					b[i] = 3 - b[i-1];
				else
					b[i] = b[i-1];
			}
			int k = 2;
			// ako je zadnja boja jednaka prvoj ne valja, probaj da nadjes mesto za flip
			if (b[n-1] == b[0]) {
				k = 3;
				for (int i=1; i<n; i++) {
					if (a[i] == a[i-1]) {
						for (int j=i; j<n; j++)
							b[j] = 3 - b[j];
						k = 2;
						break;
					}
				}
				if (k == 3)
					b[n-1] = 3;
			}

			rotate(b.begin(), b.begin()+n-rot, b.end());
			cout << k << '\n';
			for (int x : b)
				cout << x << ' ';
			cout << '\n';
		}
	}
}

// I will still practice daily...