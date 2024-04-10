#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	int*a = new int[n];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a+n);
	int s = 0;
	for (int i = n-1; i >= 0; i--) {
		s += a[i];
		if (s*2 > sum) {
			cout << n-i << endl;
			return 0;
		}
	}
	return 0;
}