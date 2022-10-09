// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

vector<int> np = {6,10,14,15,21,22};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int a;
		bool ok = false;
		cin >> a;
		for (int i=0; i<6; i++) {
			for (int j=i+1; j<6; j++) {
				for (int k=j+1; k<6; k++) {
					int r = a - np[i] - np[j] - np[k];
					if (r > 0 && r != np[i] && r != np[j] && r != np[k]) {
						ok = 1;
						cout << "YES\n";
						cout << np[i] << ' ' << np[j] << ' ' << np[k] << ' ' << r << '\n';
						i = j = k = 6;
						break;
					}
				}
			}
		}

		if (!ok) {
			cout << "NO\n";
		}
	}
}