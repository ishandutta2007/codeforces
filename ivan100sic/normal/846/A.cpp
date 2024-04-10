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

int n;
int a[105];
int d[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	d[0] = 1;
	for (int i=1; i<n; i++) {
		d[i] = 1;
		for (int j=0; j<i; j++) {
			if (a[j] <= a[i]) {
				d[i] = max(d[i], d[j] + 1);
			}
		}
	}

	cout << *max_element(d, d+n);

}