#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	long long v = 0, r = 0;
	for (char x : s) {
		if (x == '0') {
			v = 10*v + r;
			r = 0;
		} else {
			r++;
		}
	}
	v = 10*v + r;
	cout << v;
}