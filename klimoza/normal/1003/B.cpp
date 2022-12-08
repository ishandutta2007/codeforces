#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>

using namespace std;



int main() {
	int a, b, x;
	cin >> a >> b >> x;
	if (x % 2 == 1) {
		int t = (x + 1) / 2;
		a -= t;
		b -= t;
		for (int i = 0; i < a; i++) cout << "0";
		for (int i = 0; i < t; i++) cout << "01";
		for (int i = 0; i < b; i++) cout << "1";
		cout << "\n";
	}
	else {
		int t = x / 2;
		a -= t;
		b -= t;
		int s = 0;
		if (a == 0) {
			s = -1;
			b--;
		}
		else {
			s = 1;
			a--;
		}
		if (s == -1) {
			cout << "1";
		}
		for (int i = 0; i < a; i++) cout << "0";
		for (int i = 0; i < t; i++) cout << "01";
		for (int i = 0; i < b; i++) cout << "1";
		if (s == 1) {
			cout << "0";
		}
		cout << "\n";
	}
	//system("pause");
	return 0;
}