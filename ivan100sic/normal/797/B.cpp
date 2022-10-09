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

	vector<int> odd, even;
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if (x % 2 == 0) {
			even.push_back(x);
		} else {
			odd.push_back(x);
		}
	}

	int grabeven = 0;
	for (int x : even) {
		if (x > 0) {
			grabeven += x;
		}
	}

	if (odd.size() == 1) {
		// moras da uzmes
		cout << grabeven + odd[0];
		return 0;
	}

	sort(odd.begin(), odd.end());

	// uzmi najveceg pa nastavi da uzimas dok se isplati
	int grabodd = *odd.rbegin();
	odd.pop_back();
	while (odd.size() > 1) {
		int x = *odd.rbegin();
		int y = *++odd.rbegin();
		if (x + y > 0) {
			grabodd += x + y;
			odd.pop_back();
			odd.pop_back();
		} else {
			break;
		}
	}

	cout << grabodd + grabeven;
}