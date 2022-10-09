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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	long long m, b, sol = 0;
	cin >> m >> b;

	for (long long y=0; y<=b; y++) {
		long long x = m * (b - y);

		long long val = (x+y)*(x+1)*(y+1) / 2;

		sol = max(val, sol);
	}

	cout << sol;
}