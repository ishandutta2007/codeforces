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
	string s;

	cin >> s;
	n = s.size();
	map<int, char> m;
	for (int i=0; i<n; i++) {
		if (s[i] != '!') {
			m[i % 4] = s[i];
		}
	}
	map<char, int> b;
	for (int i=0; i<n; i++) {
		if (s[i] == '!') {
			b[m[i % 4]]++;
		}
	}

	cout << b['R'] << ' ' << b['B'] << ' ' << b['Y'] << ' ' << b['G'];

}