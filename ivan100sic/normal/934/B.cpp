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

	int k;
	cin >> k;
	if (k > 36) {
		cout << "-1";
	} else if (k == 0) {
		cout << "1";
	} else {
		if (k % 2)
			cout << "6";
		for (int i=0; i<k/2; i++)
			cout << "8";
	}
	cout << '\n';
}