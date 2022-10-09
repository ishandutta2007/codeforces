#include <iostream>
#include <algorithm>
using namespace std;

long long n, k, a, b;

string rp(char x, int n) {
	string u;
	while (n--) {
		u += x;
	}
	return u;
}

int main() {
	cin >> n >> k >> a >> b;
	// G..G
	{
		bool ok = true;
		long long gc = (a+k-1) / k;
		if (a < gc) {
			ok = false;
		}
		if (a > gc*k) {
			ok = false;
		}
		if (b < gc-1) {
			ok = false;
		}
		if (b > (gc-1)*k) {
			ok = false;
		}

		if (ok) {
			for (long long i=0; i<gc; i++) {
				cout << rp('G', (i+1)*a/gc - i*a/gc);
				if (i < gc-1) {
					int bc = gc-1;
					cout << rp('B', (i+1)*b/bc - i*b/bc);
				}
			}
			return 0;
		}
	}

	{
		bool ok = true;
		long long bc = (b+k-1) / k;
		if (b < bc) {
			ok = false;
		}
		if (b > bc*k) {
			ok = false;
		}
		if (a < bc-1) {
			ok = false;
		}
		if (a > (bc-1)*k) {
			ok = false;
		}

		if (ok) {
			for (long long i=0; i<bc; i++) {
				cout << rp('B', (i+1)*b/bc - i*b/bc);
				if (i < bc-1) {
					int gc = bc-1;
					cout << rp('G', (i+1)*a/gc - i*a/gc);
				}
			}
			return 0;
		}
	}

	{
		bool ok = true;
		long long bc = (b+k-1) / k;
		if (b < bc) {
			ok = false;
		}
		if (b > bc*k) {
			ok = false;
		}
		if (a < bc) {
			ok = false;
		}
		if (a > bc*k) {
			ok = false;
		}

		if (ok) {
			for (long long i=0; i<bc; i++) {
				cout << rp('B', (i+1)*b/bc - i*b/bc);
				{
					int gc = bc;
					cout << rp('G', (i+1)*a/gc - i*a/gc);
				}
			}
			return 0;
		}
	}

	cout << "NO";
}