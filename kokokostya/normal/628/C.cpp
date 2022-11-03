#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	long long res = 0;
	for (int i = 0; i < n; i++) {
		res += max(int(s[i]) - int('a'), int('z') - int(s[i]));
	}
	int i = 0;
	if (res < k) { cout << -1; }
	else {
		res = k;
		while (res > 0) {
			if (int(s[i]) - int('a') > int('z') - int(s[i])) {
				if (res > int(s[i]) - int('a')) {
					putchar('a');
					res -= int(s[i]) - int('a');
				}
				else {
					cout << char(int(s[i]) - res);
					res = 0;
				}
			}
			else {
				if (res > int('z') - int(s[i])) {
					putchar('z');
					res -= int('z') - int(s[i]);
				}
				else {
					cout << char(int(s[i]) + res);
					res = 0;
				}
			}
			i++;
		}
		for (int j = i; j < n; j++) {
			putchar(s[j]);
		}
	}
	return 0;
}