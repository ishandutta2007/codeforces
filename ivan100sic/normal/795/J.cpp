#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	string s;
	cin >> n >> k >> s;

	s = string("Y") + s + string("Y");

	int i, j, ok, found, longest, run;

	longest = 0;
	found = 0;
	run = 0;

	for (i=1; i<=n; i++) {
		if (s[i] == 'N') {
			run += 1;
		} else {
			run = 0;
		}
		if (run > longest) {
			longest = run;
		}
	}

	for (i=1; i<=n-k+1; i++) {
		ok = 1;
		for (j=i; j<i+k; j++) {
			if (s[j] == 'Y') {
				ok = 0;
			}
		}
		if (s[i-1] == 'N') {
			ok = 0;
		}
		if (s[i+k] == 'N') {
			ok = 0;
		}

		if (ok) {
			found = 1;
		}
	}

	cerr << longest << '\n';

	if (found && k >= longest) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}