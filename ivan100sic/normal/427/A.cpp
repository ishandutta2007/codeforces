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

	int n, c=0, s=0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (s+x < 0) {
			c++;
		} else {
			s += x;
		}
	}

	cout << c;
}