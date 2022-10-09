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

	int n, x;
	cin >> n >> x;

	n %= 6;

	int p[3] = {0, 1, 2};

	for (int i=0; i<n; i++) {
		if (i % 2 == 0) {
			swap(p[0], p[1]);
		} else {
			swap(p[1], p[2]);
		}
	}

	cout << p[x];
}