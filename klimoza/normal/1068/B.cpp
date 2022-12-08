#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>

using namespace std;

int main() {
	long long int b;
	cin >> b;
	long long int ans = 0;
	for (int i = 1; i <= sqrt(b); i++) {
		if (b % i == 0) {
			if (i == (double)sqrt(b)) {
				ans++;
			}
			else {
				ans += 2;
			}
		}
	}
	cout << ans << "\n";
	//system("pause");
	return 0;
}