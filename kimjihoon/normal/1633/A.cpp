#include <iostream>
#include <algorithm>
using namespace std;

int ds(int a, int b)
{
	int c = 0;
	while (a) {
		if (a % 10 != b % 10) c++;
		a /= 10; b /= 10;
	}
	return c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		int ans = 4, ra = 0;
		if (n < 100) {
			for (int i = 14; i < 100; i += 7) {
				if (ds(i, n) < ans) {
					ans = ds(i, n);
					ra = i;
				}
			}
		}
		else {
			for (int i = 105; i < 1000; i += 7) {
				if (ds(i, n) < ans) {
					ans = ds(i, n);
					ra = i;
				}
			}
		}
		cout << ra << '\n';	
	}
	return 0;
}