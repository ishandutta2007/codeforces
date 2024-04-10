#include <iostream>
#include <algorithm>
#include <set>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 15;

int x, y;

set <int> s;
void getfactors (int x) {
	for (int i = 1;i <= sqrt(x);++i) if (x % i == 0) {
		s.insert(i);
		if (i != x / i) s.insert(x / i);
	}
}

int main () {
	int T;
	cin >> T;
	while (T--) {
		cin >> x >> y;
		
		s.clear();
		getfactors(__gcd(x - 1, y - 1));
		getfactors(__gcd(x, y - 2));
		getfactors(__gcd(x - 2, y));
		getfactors(__gcd(x - 1, __gcd(y, y - 2)));
		getfactors(__gcd(y - 1, __gcd(x, x - 2)));
		getfactors(__gcd(__gcd(x, x - 2), __gcd(y, y - 2)));
		
		cout << s.size() << ' ';
		for (int i : s) {
			cout << i << ' ';
		}
		cout << endl;
	}
}