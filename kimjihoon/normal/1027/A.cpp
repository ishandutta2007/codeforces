#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	for (int ti = 1; ti <= tc; ti++) {
		int n;
		string s;
		cin >> n >> s;
		int f = 1;
		for (int i = 0; i < s.length() / 2; i++) {
			int t = abs(s[i] - s[s.length() - i - 1]);
			if (t != 0 && t != 2) {
				f = 0;
				break;
			}
		}
		if (f == 1)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}