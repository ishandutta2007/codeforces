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

	int sol = 0;

	for (char x : s) {
		bool gornji = '@' < x && '[' > x;
		bool donji = '`' < x && '{' > x;

		int p1 = (int)gornji * (int)(x - 'A' + 1);
		int p2 = (int)donji * (int)(x - 'a' + 1);

		sol += p1 - p2;
	}

	cout << sol;
}