#include <iostream>
#include <algorithm>
using namespace std;

int a[1005];

int main() {
	int n, k, c=0;
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	for (int i=0; i<n; i++) {
		while (a[i] > 2*k) {
			k = 2*k;
			c++;
		}
		k = max(k, a[i]);
	}
	cout << c;
}