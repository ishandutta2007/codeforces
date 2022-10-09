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

	int n;
	int poz=0, neg=0;
	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		if (x < 0)
			neg++;
		else if (x > 0)
			poz++;
	}

	if (2*poz >= n) {
		cout << "1\n";
	} else if (2*neg >= n) {
		cout << "-1\n";
	} else {
		cout << "0\n";
	}
}