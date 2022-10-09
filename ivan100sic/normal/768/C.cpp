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

int c[2][1024];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k, x;

	cin >> n >> k >> x;
	for (int i=1; i<=n; i++) {
		int y;
		cin >> y;
		c[0][y]++;
	}

	for (int kk=1; kk<=k; kk++) {
		auto old = c[1-(kk&1)];
		auto nov = c[kk&1];

		memset(nov, 0, sizeof(c[0]));

		int start = 1;
		for (int i=0; i<1024; i++) {
			if ((old[i] & 1) == 0) {
				nov[i] += old[i] >> 1;
				nov[i ^ x] += old[i] >> 1;
			} else if (start) {
				nov[i] += old[i] >> 1;
				nov[i ^ x] += 1 + (old[i] >> 1);
				start = 0;
			} else {
				nov[i] += 1 + (old[i] >> 1);
				nov[i ^ x] += old[i] >> 1;
				start = 1;
			}
		}
	}

	int f=-1, l=-1;
	for (int i=0; i<1024; i++) {
		if (c[k%2][i]) {
			if (f == -1) {
				f = i;
			}
			l = i;
		}
	}
	cout << l << ' ' << f;
}