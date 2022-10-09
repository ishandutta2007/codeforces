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

	int n, h=0, bl=0, k=0;
	cin >> n;

	while (1) {
		h++;
		bl += h*(h+1) / 2;
		if (bl <= n) {
			k = h;
		} else {
			break;
		}
	}

	cout << k;

}