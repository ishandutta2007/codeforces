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

	int n1, n2, k1, k2;

	cin >> n1 >> n2;

	if (n1 > n2) {
		cout << "First";
	} else {
		cout << "Second";
	}

}