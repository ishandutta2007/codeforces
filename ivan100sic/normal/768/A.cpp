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

	map<int, int> s;
	int x, n;

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> x;
		s[x]++;
	}

	if (s.size() == 1) {
		cout << 0;
		return 0;
	}

	cout << (n - s.begin()->second - s.rbegin()->second);
}