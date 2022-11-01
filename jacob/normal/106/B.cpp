#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int res = 0;
	int rc = 10000000;
	vector<int> a1(n), a2(n), a3(n), a4(n);
	for (int i = 0; i < n; i++) {
		cin >> a1[i] >> a2[i] >> a3[i] >> a4[i];
	}
	for (int i = 0; i < n; i++) {
		bool g = true;
		for (int j = 0; j < n; j++) {
			if (a1[j] > a1[i] && a2[j] > a2[i] && a3[j] > a3[i]) {
				g = false;
				break;
			}
		}
		if (!g) continue;
		if (rc > a4[i])
		{
			rc = a4[i];
			res = i + 1;
		}
	}
	cout << res << endl;
	return 0;
}