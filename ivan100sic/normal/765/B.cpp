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

	string s;
	cin >> s;

	char a = 'a';

	for (char x : s) {
		if (x > a) {
			cout << "NO";
			return 0;
		} else if (x == a) {
			a++;
		}
	}
	cout << "YES";
	return 0;
}