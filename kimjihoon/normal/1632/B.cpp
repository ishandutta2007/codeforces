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
		int t = 1;
		while (t * 2 <= n - 1)
			t *= 2;
		for (int i = n - 1; i >= t; i--)
			cout << i << " ";
		for (int i = 0; i < t; i++)
			cout << i << " ";
		cout << '\n';
	}
	return 0;
}