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
	cin >> n;
	int last = 0, sol = 0;
	while (n--) {
		int x;
		cin >> x;
		if (x == 1) {
			if (last == 1)
				sol += 1;
			else
				sol += 2;
		} else {

		}
		last = x;
	}	
	cout << max(0, sol-1) << '\n';
}