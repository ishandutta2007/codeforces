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

	set<char> c;

	string s;
	while (cin >> s) {
		for (char x : s) {
			if ('a' <= x && x <= 'z') {
				c.insert(x);
			}
		}
	}

	cout << c.size();


}