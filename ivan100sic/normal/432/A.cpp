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

	int n, k, c=0;
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		if (x+k <= 5) {
			c++;
		}
	}
	cout << c/3;

}