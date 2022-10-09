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

	int n;
	cin >> n;

	string s;
	cin >> s;
	for (int i=0; i<n; i++) {
		cin >> s;
	}

	if (n % 2 == 0) {
		cout << "home";
	} else {
		cout << "contest";
	}
}