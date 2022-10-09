#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, c=0;
	int a[105], b[105];

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i] >> b[i];
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i == j) {
				continue;
			}

			if (a[i] == b[j]) {
				c++;
			}

		}
	}

	cout << c;

}