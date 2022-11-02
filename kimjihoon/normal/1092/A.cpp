#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, k; cin >> n >> k;
		for (int i = 0; i < k; i++)
			for (int j = 0; j < n / k; j++)
				cout << (char)('a' + i);
		for (int j = 0; j < n % k; j++)
			cout << "a";
		cout << '\n';
	}
	return 0;
}