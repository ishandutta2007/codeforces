#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	vector<char> isprime(2000001, 1);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	isprime[0] = 0;
	isprime[1] = 0;
	for (int i = 2; i < 2000001; i++) {
		if (isprime[i]) {
			if (i * 1ll * i < 2000001) {
				for (int j = i * i; j < 2000001; j += i) {
					isprime[j] = 0;
				}
			}
		}
	}
	int a = 1999999, b = 1999999;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (isprime[arr[i] + arr[j]] && (arr[i] == 1 || arr[j] == 1 || a == 1999999)) { a = arr[i]; b = arr[j]; }
		}
	}
	if (a == 1999999) {
		
		cout << 1 << '\n';
		cout << arr[0];
	}
	else {
		if (a == 1 || b == 1) {
			int res = 0;
			bool is = 1;
			for (int i = 0; i < n; i++) {
				if (arr[i] == 1) { res++; }
				else {
					if (is && isprime[arr[i] + 1]) { res++; is = 0; }
				}
			}
			cout << res << '\n';
			is = 1;
			for (int i = 0; i < n; i++) {
				if (arr[i] == 1) { cout << 1 << ' '; }
				else {
					if (is && isprime[arr[i] + 1]) { cout << arr[i] << ' '; is = 0; }
				}
			}
		}
		else { cout << 2 << '\n';
		cout << a << ' ' << b;
		}
	}

	return 0;
}