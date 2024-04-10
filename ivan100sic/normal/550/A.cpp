#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void ye() {
	cout << "YES\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;

	int n = s.size();
	int lab = 123123123, lba = 123123123;

	for (int i=0; i<n-1; i++) {
		if (s.substr(i, 2) == "AB") {
			if (i - lba >= 2)
				ye();
			lab = min(lab, i);
		} else if (s.substr(i, 2) == "BA") {
			if (i - lab >= 2)
				ye();
			lba = min(lba, i);
		}
	}
	cout << "NO\n";
}