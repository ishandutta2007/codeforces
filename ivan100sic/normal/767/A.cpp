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

	set<int> a;
	int n, z;
	cin >> n;
	z = n;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		a.insert(x);

		while (1) {
			if (a.size() && *a.rbegin() == z) {
				cout << z << ' ';
				a.erase(z--);
			} else {
				break;
			}
		}
		cout << '\n';
	}
}