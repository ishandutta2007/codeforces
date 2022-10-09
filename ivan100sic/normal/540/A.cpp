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

	int n, s=0;
	string a, b;
	cin >> n >> a >> b;

	for (int i=0; i<n; i++) {
		int d = abs((int)(a[i]) - (int)(b[i]));
		d = min(d, 10-d);
		s += d;
	}

	cout << s;

}