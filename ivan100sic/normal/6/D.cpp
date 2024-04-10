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

// zadnja 3 i njihov hp
int h[15];
int hl[15];
int s[15];
int a, b, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> a >> b;
	for (int i=1; i<=n; i++) {
		cin >> h[i];
		h[i]++;
	}

	if (n == 3) {
		int sol = max(max((h[1] + b - 1)/b, (h[2] + a - 1)/a), (h[3] + b - 1)/b);
		cout << sol << '\n';
		while (sol--) {
			cout << "2 ";
		}
		return 0;
	}

	s[2] += (h[1] + b - 1) / b;
	s[n-1] += (h[n] + b - 1) / b;

	h[1] -= b*s[2];
	h[2] -= a*s[2];
	h[3] -= b*s[2];

	h[n-0] -= b*s[n-1];
	h[n-1] -= a*s[n-1];
	h[n-2] -= b*s[n-1];

	int komb = 1;
	for (int i=0; i<n-2; i++) {
		komb *= 9;
	}

	int sol = s[2] + s[n-1];
	int soll[15] = {0};
	int best = 1e9;
	int sd[15] = {0};

	for (int mask=0; mask<komb; mask++) {

		int bad = 0, sum = 0;

		for (int i=1; i<=n; i++) {
			sum += sd[i];
			if (h[i] - a*sd[i] - b*sd[i-1] - b*sd[i+1] > 0) {
				bad = 1;
			}
		}

		if (bad == 0) {
			if (sum < best) { 
				best = sum;
				copy(sd, sd+n+1, soll);
			}
		}

		{
			int i = n-1;
			sd[i]++;
			while (sd[i] == 9) {
				sd[i] = 0;
				sd[--i]++;
			}
		}
	}

	soll[2] += s[2];
	soll[n-1] += s[n-1];

	cout << accumulate(soll, soll+n+1, 0) << '\n';

	for (int i=1; i<=n; i++) {
		while (soll[i]--) {
			cout << i << ' ';
		}
	}

}