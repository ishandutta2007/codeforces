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

	int n, ones=0, zeros=0;
	string s;

	cin >> n >> s;
	for (char x : s) {
		if (x == '0') {
			zeros++;
		} else {
			ones++;
		}
	}

	cout << abs(ones - zeros);
}