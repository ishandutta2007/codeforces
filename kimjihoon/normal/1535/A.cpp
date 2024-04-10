#include <iostream>
#include <algorithm>
using namespace std;

int a[19];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int mx0 = 0, mx1 = 0;
		for (int i = 1; i <= 4; i++) {
			cin >> a[i];
			if (a[mx0] <= a[i]) {
				mx1 = mx0;
				mx0 = i;
			}
			else if (a[mx1] < a[i])
				mx1 = i;
		}
		if ((mx0 <= 2) == (mx1 <= 2)) cout << "NO" << '\n';
		else cout << "YES" << '\n';
	}
	return 0;
}