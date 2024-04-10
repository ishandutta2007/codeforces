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

int gcd(int a, int b) {
	int t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

int n;
int a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
	
	cin >> n;
	
	int g = 0;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		g = gcd(a[i], g);
	}

	if (g > 1) {
		cout << "YES\n0";
		return 0;
	}

	int c = 0;
	int runlen = 0;
	for (int i=1; i<=n; i++) {
		if (a[i] % 2) {
			runlen++;
		} else {
			if (runlen % 2 == 0) {
				c += runlen / 2;
			} else {
				c += runlen / 2 + 2;
			}

			runlen = 0;
		}
	}

	if (runlen % 2 == 0) {
		c += runlen / 2;
	} else {
		c += runlen / 2 + 2;
	}


	cout << "YES\n" << c;


}