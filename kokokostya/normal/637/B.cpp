#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

set < string > a;
vector < string > b;

int main() {
	int n;
	cin >> n;
	b.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		if (a.find(b[i]) == a.end())
			cout << b[i] << '\n';
		a.insert(b[i]);
	}
	return 0;
}