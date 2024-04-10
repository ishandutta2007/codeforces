#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


long long int gcd(long long int a, long long int b) {
	if (a == 0) return b;
	if (b == 0) return a;
	return gcd(b, a % b);
}



int main() {
	int n;
	cin >> n;
	if (n <= 2) {
		cout << "No\n";
	}
	else {
		long long int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += i;
		}
		if (n % 4 == 3) {
			cout << "Yes\n";
			cout << n / 2 << " ";
			for (int i = 2; i <= n; i += 2) {
				cout << i << " ";
			}
			cout << "\n" << n / 2 + 1 << " ";
			for (int i = 1; i <= n; i += 2) {
				cout << i << " ";
			}
			cout << "\n";
		}
		else if (n % 4 == 0) {
			cout << "Yes\n";
			cout << n / 2 << " ";
			for (int i = 2; i <= n; i += 2) {
				cout << i << " ";
			}
			cout << "\n" << n / 2  << " ";
			for (int i = 1; i <= n; i += 2) {
				cout << i << " ";
			}
			cout << "\n";
		}
		else {
			bool fl = false;
			long long int l = sum / 2;
			long long int r = sum / 2 + 1;
			while (l != 1) {
				if (gcd(l, r) != 1) {
					fl = true;
					break;
				}
				l--;
				r++;
			}
			if (!fl) {
				cout << "No\n";
			}
			else {
				vector<bool> used(n + 1);
				int ind = n;
				int count = 0;
				while (ind < l) {
					used[ind] = true;
					l -= ind;
					count++;
					ind--;
				}
				if (l != 0) {
					used[l] = true;
					count++;
				}
				cout << "Yes\n";
				cout << count << " ";
				for (int i = 1; i <= n; i++) {
					if (used[i]) {
						cout << i << " ";
					}
				}
				cout << "\n";
				cout << n - count << " ";
				for (int i = 1; i <= n; i++) {
					if (!used[i]) {
						cout << i << " ";
					}
				}
				cout << "\n";
			}
		}
	}
	//system("pause");
	return 0;
}