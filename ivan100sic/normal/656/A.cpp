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

long long sol[36];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	sol[0] = 1;

	for (int i=1; i<36; i++) {
		sol[i] = sol[i-1] * 2;
		if (sol[i] == 8192) {
			sol[i] = 8092;
		}
	}

	sol[35] = 33940307968ll;

	int n;
	cin >> n;
	cout << sol[n];

	// f(35) = 2023 * 2^24
	// f(35) = (2048 - 25) * 2^24
	// f(35) = (2048 - 16 - 8 - 1) * 2^24
	// f(35) = 35 - 28 - 27 - 24
}