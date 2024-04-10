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

map<string, int> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	m["Tetrahedron"] = 4;
	m["Cube"] = 6;
	m["Octahedron"] = 8;
	m["Dodecahedron"] = 12;
	m["Icosahedron"] = 20;

	int n, sol = 0;
	string s;

	cin >> n;
	while (n--) {
		cin >> s;
		sol += m[s];
	}
	cout << sol;
}