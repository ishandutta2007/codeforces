#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;

int gcd(int a, int b) {
	int t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;

	int lo = 0, up = 0;

	for (char x : s) {
		if (x >= 'a') {
			lo++;
		} else {
			up++;
		}
	}

	char tgt = (lo >= up ? ('a' - 1) : ('A' - 1));

	for (char& x : s) {
		x = tgt + (x & 31);
	}

	cout << s;

}