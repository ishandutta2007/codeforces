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

	int n;
	cin >> n;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	if (n % 2 == 0) {
		cout << (n/2-1);
		return 0;
	} else {
		cout << (n/2);
		return 0;
	}
}