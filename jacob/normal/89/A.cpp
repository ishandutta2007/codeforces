#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int main(void) {
	int n, m, k;
	cin >> n >> m >> k;
	if (n % 2 == 0) {
		cout << 0 << endl;
		return 0;
	}
	int o = m / ((n + 1) / 2);
	long long res = o * (long long)k;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (i % 2 == 0 && t < res) 
			res = t;
	}
	cout << res << endl;
	return 0;
}