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
	int t;
	cin >> t;
	long long int t1, t2;
	for (int i = 0; i < t; i++) {
		cin >> t1 >> t2;
		if (t2 + 1 == t1) {
			long long int h = t1 + t2;
			bool fl = false;
			for (int i = 2; i <= sqrt(h); i++) {
				if (h % i == 0) {
					fl = true;
					break;
				}
			}
			if (!fl) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
		else {
			cout << "NO\n";
		}
	}
	//system("pause");
	return 0;
}