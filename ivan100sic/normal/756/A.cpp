#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int p[200005], b[200005], v[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> p[i];
	}
	for (int i=1; i<=n; i++) {
		cin >> b[i];
	}

	int sol = 0;
	if (accumulate(b+1, b+n+1, 0) % 2 == 0) {
		sol++;
	}

	int c=0;
	for (int i=1; i<=n; i++) {
		if (!v[i]) {
			int x = i;
			v[i] = 1;
			c++;
			do {
				x = p[x];
				v[x] = 1;
			} while (x != i);
		}
	}

	if (c > 1) {
		sol += c;
	}

	cout << sol;
}