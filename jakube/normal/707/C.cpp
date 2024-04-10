#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

	int n;
	cin >> n;

	if (n < 3) {
		cout << -1 << endl;
		return 0;
	}
	if (n % 2 == 0) {
		long long u = n / 2;
		long long v = 1;
		cout << (u * u - v * v) << " " << (u * u + v * v) << endl;
		return 0;
	}

	int p;
	for (p = 3; p*p < n; p += 2) {
		if (n % p == 0) {
			long long a = p;
			long long b = n / p;
			if (a > b)
			{
				long long t = a;
				a = b;
				b = t;
			}
			long long u = (a + b) / 2;
			long long v = (b - a) / 2;
			
			cout << (2*u*v) << " " << (u * u + v * v) << endl;
			return 0;
		}
	}

	if (p*p == n)
	{
		
		long long u = (1 + n) / 2;
		long long v = (n - 1) / 2;
		
		cout << (2*u*v) << " " << (u * u + v * v) << endl;
		return 0;

	}
	else {
		long long b = n;
		long long a = 1;

		long long u = (a + b) / 2;
		long long v = (b - a) / 2;
		
		cout << (2*u*v) << " " << (u * u + v * v) << endl;
		return 0;
	}
}