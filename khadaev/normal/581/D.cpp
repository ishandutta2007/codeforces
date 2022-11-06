#include <bits/stdc++.h>
using namespace std;

bool check(int x1, int y1, int x2, int y2, int x3, int y3) {
	if (x1 == x2 && x2 == x3 && x3 == y1 + y2 + y3) {
		cout << x1 << "\n";
		for (int i = 0; i < y1; ++i) {
			for (int j = 0; j < x1; ++j) cout << "A";
			cout << "\n";
			};
		for (int i = 0; i < y2; ++i) {
			for (int j = 0; j < x1; ++j) cout << "B";
			cout << "\n";
			};
		for (int i = 0; i < y3; ++i) {
			for (int j = 0; j < x1; ++j) cout << "C";
			cout << "\n";
			};
		return true;
		};
	if (x1 == x2 + x3 && y2 == y3 && x1 == y1 + y2) {
		cout << x1 << "\n";
		for (int i = 0; i < y1; ++i) {
			for (int j = 0; j < x1; ++j) cout << "A";
			cout << "\n";
			};
		for (int i = 0; i < y2; ++i) {
			for (int j = 0; j < x2; ++j) cout << "B";
			for (int j = 0; j < x3; ++j) cout << "C";
			cout << "\n";
			};
		return true;
		};
	if (x2 == x1 + x3 && y1 == y3 && x2 == y1 + y2) {
		cout << x2 << "\n";
		for (int i = 0; i < y2; ++i) {
			for (int j = 0; j < x2; ++j) cout << "B";
			cout << "\n";
			};
		for (int i = 0; i < y1; ++i) {
			for (int j = 0; j < x1; ++j) cout << "A";
			for (int j = 0; j < x3; ++j) cout << "C";
			cout << "\n";
			};
		return true;
		};
	if (x3 == x2 + x1 && y2 == y1 && x3 == y3 + y2) {
		cout << x3 << "\n";
		for (int i = 0; i < y3; ++i) {
			for (int j = 0; j < x3; ++j) cout << "C";
			cout << "\n";
			};
		for (int i = 0; i < y2; ++i) {
			for (int j = 0; j < x1; ++j) cout << "A";
			for (int j = 0; j < x2; ++j) cout << "B";
			cout << "\n";
			};
		return true;
		};
	return false;
	};

int main() {
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	for (int q = 0; q < 2; ++q) {
		swap(x1, y1);
		for (int w = 0; w < 2; ++w) {
			swap(x2, y2);
			for (int e = 0; e < 2; ++e) {
				swap(x3, y3);
				if (check(x1, y1, x2, y2, x3, y3)) return 0;
				};
			};
		};
	cout << "-1\n";
}