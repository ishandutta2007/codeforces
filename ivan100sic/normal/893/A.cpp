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

	int a=1, b=2, c=3;
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if (x == c)
			return cout << "NO", 0;

		if (x == a) {
			swap(b, c);
		} else {
			swap(a, c);
		}
	}
	cout << "YES";
}