#include <iostream>
using namespace std;

int r[4][4] = { { 8, 9, 1, 13 }, { 3, 12, 7, 5 }, { 0, 2, 4, 11 }, { 6, 10, 15, 14 } };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << r[i % 4][j % 4] + ((i / 4) * (n / 4) + (j / 4)) * 16 << " ";
		cout << '\n';
	}
	return 0;
}