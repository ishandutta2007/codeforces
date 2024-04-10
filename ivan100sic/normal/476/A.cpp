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

	int n, m;
	cin >> n >> m;

	int l = (n+1)/2;
	int r = n;

	int x = l;
	while (x % m) {
		x++;
	}

	if (x <= r) {
		cout << x;
	} else {
		cout << -1;
	}
}