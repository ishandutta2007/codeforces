#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		if (n == 1)
			cout << "a\n";
		else if (n == 2)
			cout << "ab\n";
		else if (n & 1) {
			for (int i = 0; i < n / 2 - 1; i++)
				cout << "a";
			cout << "bc";
			for (int i = 0; i < n / 2; i++)
				cout << "a";
			cout << '\n';
		}
		else {
			for (int i = 0; i < n / 2 - 1; i++)
				cout << "a";
			cout << "b";
			for (int i = 0; i < n / 2; i++)
				cout << "a";
			cout << '\n';
		}
	}
	return 0;
}