#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int px, py; cin >> px >> py;
		string s; cin >> s;
		int xl = 0, xr = 0, yl = 0, yr = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'L') xl--;
			else if (s[i] == 'R') xr++;
			else if (s[i] == 'D') yl--;
			else yr++;
		}
		if (xl <= px && px <= xr && yl <= py && py <= yr) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}