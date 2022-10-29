#include<iostream>
#include<algorithm>
using namespace std;
int a[300010];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		bool can = 1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			if (a[i] < min(i, n - i - 1)) can = 0;
		}
		if ((n & 1) == 0) {
			if (a[n / 2] == n / 2 - 1 && a[n / 2 - 1] == n / 2 - 1) can = 0;
		}
		if (can) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}