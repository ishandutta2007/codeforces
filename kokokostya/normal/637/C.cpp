#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

vector < string > b;

int f(string a, string b) {
	int cn = 0;
	for (int i = 0; i < 6; i++) {
		if (a[i] != b[i])
			cn++;
	}
	return (cn - 1) / 2;
}

int main() {
	int n;
	cin >> n;
	b.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	if (n == 1) {
		cout << 6;
		return 0;
	}
	int mn = 1e9;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			mn = min(mn, f(b[i], b[j]));
		}
	}
	cout << mn;
	return 0;
}