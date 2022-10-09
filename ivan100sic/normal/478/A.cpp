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

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e;
	f = a+b+c+d+e;

	if (f % 5 || f == 0) {
		cout << -1;
	} else {
		cout << f/5;
	}
}