#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		int n; cin >> n;
		cout << n / 2 << '\n';
	}
	return 0;
}