#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	pair<int, char> a = { 0, 'R' }, b = { 0, 'B' }, c = { 0 ,'G' };
	int n;
	cin >> n;
	char ch;
	for (int i = 0; i < n; i++) {
		cin >> ch;
		if (ch == 'R') { a.first++; }
		else {
			if (ch == 'B') { b.first++; }
			else { c.first++; }
		}
	}
	if (a.first > b.first) { swap(a, b); }
	if (c.first < b.first) { swap(c, b); }
	if (a.first > b.first) { swap(a, b); }
	if (b.first == 0) { cout << c.second; return 0; }
	if (a.first == 0 && c.first == 1) { cout << a.second; return 0; }
	if (a.first == 0 && b.first == 1) {
		if (a.second < b.second) {
			cout << a.second << b.second;
		}
		else {
			cout << b.second << a.second;
		}
		return 0;
	}
	else {
		if (a.second > b.second) { swap(a.second, b.second); }
		if (c.second < b.second) { swap(c.second, b.second); }
		if (a.second > b.second) { swap(a.second, b.second); }
	}
	cout << a.second << b.second << c.second;
	return 0;
}