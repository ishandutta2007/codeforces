#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		long long x, y;
		cin >> y >> x;
		if ((x + y) % 2 == 0) {
			if (n % 2 == 0) 
				cout << (y - 1) * (n / 2) + (x + 1) / 2 << '\n';
			else {
				long long t = (((y + 1) / 2 * 2 - 2) / 2) * n;
				if (y % 2 == 1)
					t += (x + 1) / 2;
				else
					t += (n + 1) / 2 + x / 2;
				cout << t << '\n';
			}
		}
		else {
			if (n % 2 == 0) 
				cout << (y - 1) * (n / 2) + (x + 1) / 2 + n * n / 2<< '\n';
			else {
				long long t = (((y + 1) / 2 * 2 - 2) / 2) * n + n * n / 2 + 1;
				if (y % 2 == 1)
					t += x / 2;
				else
					t += n / 2 + (x + 1) / 2;
				cout << t << '\n';
			}
		}
	}
	return 0;
}