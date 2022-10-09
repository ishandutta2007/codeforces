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

	int n, c=0;
	cin >> n;
	while (n > 0) {
		if (n % 8 == 1) {
			c++;
		}
		n /= 8;
	}
	cout << c;
}