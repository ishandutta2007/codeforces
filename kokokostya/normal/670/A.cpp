#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int mx;
	int mn = (n / 7) * 2;
	if (n % 7 == 6) { mn++; }
	if (n > 2) {
		 mx = 2;
		mx += ((n - 2) / 7) * 2;
		if (((n - 2) % 7) == 6) { mx++; }
	}
	else { mx = n; }
	cout << mn << ' ' << mx;
	return 0;
}