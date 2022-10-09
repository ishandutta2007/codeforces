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

int n, k;
long long a[100005], z[100005];

long long solve(long long diff) {
	map<long long, int> br;
	long long sol = 0;

	br[0] = 1;

	for (int i=1; i<=n; i++) {
		sol += br[z[i] - diff];
		br[z[i]]++;
	}

	return sol;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		z[i] = z[i-1] + a[i];
	}

	long long x = 1, sol = 0;

	if (k == -1) {
		sol += solve(-1);
		sol += solve(1);
	} else if (k == 1) {
		sol += solve(1);
	} else {
		while (abs(x) <= 1e16) {
			sol += solve(x);
			x *= k;
		}
	}	

	cout << sol;
}