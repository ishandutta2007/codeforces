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

	int k, r;
	cin >> k >> r;

	for (int i=1; i<=10; i++) {
		int x = k*i;
		if (x % 10 == 0 || x % 10 == r) {
			cout << i;
			return 0;
		}
	}
}