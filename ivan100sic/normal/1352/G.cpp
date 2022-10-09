// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct _in {
	template<class T>
	operator T() {
		T x;
		cin >> x;
		return x;
	}
} in;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t = in;
	while (t--) {
		int n = in;
		if (n < 4) {
			cout << "-1\n";
		} else if (n == 4) {
			cout << "3 1 4 2\n";
		} else {
			for (int i=1; i<=n; i+=2) {
				cout << i << ' ';
			}
			if (n % 2 == 1) {
				cout << n-3 << ' ' << n-1 << ' ';
				for (int i=n-5; i>0; i-=2)
					cout << i << ' ';
			} else {
				cout << n-4 << ' ' << n << ' ' << n-2 << ' ';
				for (int i=n-6; i>0; i-=2)
					cout << i << ' ';
			}
			cout << '\n';
		}
	}
}