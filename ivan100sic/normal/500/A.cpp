#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;

int a[100005], n, t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> t;
	for (int i=1; i<n; i++) {
		cin >> a[i];
	}

	int x = 1;

	while (x < t) {
		x += a[x];
	}

	cout << (x == t ? "YES" : "NO");

}