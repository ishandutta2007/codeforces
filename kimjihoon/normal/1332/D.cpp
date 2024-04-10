#include <iostream>
using namespace std;

int ans[3][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k; cin >> k;
	cout << 3 << " " << 3 << '\n';
	int b = (1 << 17), r = (1 << 18) - 1;
	ans[0][0] = ans[1][1] = ans[2][1] = r;
	ans[0][1] = b;
	ans[1][0] = ans[2][2] = k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << ans[i][j] << " ";
		cout << '\n';
	}
	return 0;
}