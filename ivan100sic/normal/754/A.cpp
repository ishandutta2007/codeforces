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

	int n;
	cin >> n;
	int a[105];

	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	if (accumulate(a+1, a+n+1, 0) != 0) {
		cout << "YES\n1\n1 " << n;
	} else {
		int y = find_if(a+1, a+n+1, [](int x) { return x; }) - a;
		if (y != n+1) {
			cout << "YES\n2\n1 " << y << "\n" << y+1 << ' ' << n;
		} else {
			cout << "NO";
		}
	}

}