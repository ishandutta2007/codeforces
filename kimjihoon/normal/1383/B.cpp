#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int a[100009];
bool d[1009][1009][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		int s = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			s = (s ^ a[i]);
		}
		if (!s) {
			cout << "DRAW" << '\n';
			continue;
		}
		int r = 1;
		while (r * 2 <= s)
			r *= 2;
		int s1 = 0, s2 = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] & r)
				s1++;
			else
				s2++;
		}
		if (s1 % 4 == 1 || s2 % 2 == 1) cout << "WIN" << '\n';
		else cout << "LOSE" << '\n';
	}
	return 0;
}