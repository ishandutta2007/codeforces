#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		int mx0 = 0, mx1 = 0;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			if (mx0 < a) {
				mx1 = mx0; mx0 = a;
			}
			else if (mx1 < a)
				mx1 = a;
		}
		cout << min(n - 2, mx1 - 1) << '\n';
	}
	return 0;
}