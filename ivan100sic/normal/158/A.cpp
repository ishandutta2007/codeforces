#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int a[105], n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	int c = 0;

	for (int i=1; i<=n; i++) {
		if (a[i] > 0 && a[i] >= a[k]) {
			c++;
		}
	}

	cout << c;
}