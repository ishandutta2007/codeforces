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

	int d = 1, n, m;
	cin >> n >> m;
	while (1) {
		if (n == 0) {
			cout << d-1;
			break;
		}
		n--;
		if (d % m == 0) {
			n++;
		}
		d++;
	}

}