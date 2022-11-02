#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int mx0 = -1, mx1 = -1, mn0 = 1000000, mn1 = 1000000;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (mx0 < a) {
			mx1 = mx0; mx0 = a;
		}
		else if (mx1 < a)
			mx1 = a;
		if (mn0 > a) {
			mn1 = mn0; mn0 = a;
		}
		else if (mn1 > a)
			mn1 = a;
	}
	cout << min(mx0 - mn1, mx1 - mn0) << '\n';
	return 0;
}