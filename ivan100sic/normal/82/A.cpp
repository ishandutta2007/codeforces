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

	vector<string> a = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

	long long mul = 1, n;
	cin >> n;
	n--;
	while (1) {
		if (n < 5*mul) {
			cout << a[n/mul];
			break;
		} else {
			n -= 5*mul;
			mul *= 2;
		}
	}

}