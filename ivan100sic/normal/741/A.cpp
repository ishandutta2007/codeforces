#include <iostream>
#include <string>
#include <vector>
using namespace std;

int p[105], n;

long long gcd(long long a, long long b) {
	long long t;
	while (a) {
		t = a;
		a = b % a;
		b = t; 
	}
	return b;
}

long long nzs(long long a, long long b) {
	long long g = gcd(a, b);
	return a/g * b;
}

int main() {
	cin >> n;

	int sol = 1;
	for (int i=1; i<=n; i++) {
		cin >> p[i];
	}

	for (int i=1; i<=n; i++) {

		int j=0, x=i;
		for (j=1; j<=n; j++) {
			x = p[x];
			if (x == i) {
				break;
			}
		}

		if (j > n) {
			sol = -1;
			break;
		}

		if (j % 2 == 0) {
			sol = nzs(sol, j / 2);
		} else {
			sol = nzs(sol, j);
		}
	}

	cout << sol;
}