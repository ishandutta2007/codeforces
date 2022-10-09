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

int n, m;
int x[5005];

struct hole {
	int p, c;

	bool operator< (const hole& other) const {
		return p < other.p;
	}

} h[5005];

long long d[2][5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> x[i];
	}
	for (int i=1; i<=m; i++) {
		cin >> h[i].p >> h[i].c;
		h[i].c = min(h[i].c, n);
	}

	sort(x+1, x+n+1);
	sort(h+1, h+m+1);

	memset(d, 63, sizeof(d));
	d[0][0] = 0;

	for (int i=1; i<=m; i++) {
		auto nu = d[i%2];
		auto ol = d[1-i%2];

		nu[0] = 0;
		int k = 0;

		for (int j=1; j<=n; j++) {
			nu[j] = nu[j-1] + abs(x[j] - h[i].p);
			while (k < j) {
				long long delta = ol[k+1] - ol[k] - abs(x[k+1] - h[i].p);
				if (delta < 0 || j-k > h[i].c) {
					nu[j] += delta;
					k++;
				} else {
					break;
				}
			}
		}
	}

	long long sol = d[m%2][n];	

	if (sol > 1e16) {
		sol = -1;
	}

	cout << sol;
}