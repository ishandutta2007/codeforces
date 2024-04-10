#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	int n = s.size();
	char sofar = 122;
	for (int i=0; i<n; i++) {
		if (s[i] > sofar) {
			cout << "Ann\n";
		} else {
			cout << "Mike\n";
		}

		sofar = min(sofar, s[i]);
	}
}