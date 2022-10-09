#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	string s;
	map<char, int> l;
	l['A'] = 0;
	l['C'] = 1;
	l['G'] = 2;
	l['T'] = 3;
	l['?'] = 4;

	int br[5] = {0, 0, 0, 0, 0};

	cin >> n >> s;
	for (char x : s) {
		br[l[x]]++;
	}

	for (char& x : s) {
		if (x == '?') {
			int id = min_element(br, br+4) - br;
			br[id]++;
			x = "ACGT"[id];
		}
	}

	if (*min_element(br, br+4) != *max_element(br, br+4)) {
		cout << "===";
	} else {
		cout << s;
	}

}