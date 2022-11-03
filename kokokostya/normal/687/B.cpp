

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	long long res = 1;
	vector<long long> arr(n);
	for (int i = 0; i < n; i++) {
		scanf("%i64d", &arr[i]);
	}
	vector<int> a(1000000);
	bool tr = 1;
	for (int i = 2; i < 1000000; i++) {
		while (k % i == 0) { k /= i; a[i]++; }
		if (a[i]) {
			bool is = 0;
			for (int j = 0; j < n; j++) {
				int mx = 0;
				while (arr[j] % i == 0 && mx < a[i]) { arr[j] /= i; mx++; }
				if (mx >= a[i]) { is = 1; }
			}
			if (!is) { tr = 0; }
		}
	}
	if (tr) { cout << "Yes"; }
	else { cout << "No"; }
	return 0;
}