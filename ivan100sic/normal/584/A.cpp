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

	int a, b;
	cin >> a >> b;
	if (b == 10) {
		if (a == 1) {
			cout << -1;
		} else {
			cout << 1;
			for (int i=1; i<a; i++) {
				cout << 0;
			}
		}
	} else {
		for (int i=0; i<a; i++) {
			cout << b;
		}
	}

}