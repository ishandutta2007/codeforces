#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int l[300009], r[300009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		string s; cin >> s;
		for (int i = 0; i < n; i++) {
			if (i == 0 || s[i] == s[i - 1]) l[i] = 1;
			else l[i] = l[i - 1] + 1;
		}
		for (int i = n - 1; i >= 0; i--) {
			if (i == n - 1 || s[i] == s[i + 1]) r[i] = 1;
			else r[i] = r[i + 1] + 1;
		}
		for (int i = 0; i <= n; i++) {
			int p = 1;
			if (i > 0 && s[i - 1] == 'L') p += l[i - 1];
			if (i < n && s[i] == 'R') p += r[i];
			cout << p << " ";
		}
		cout << '\n';
	}
	return 0;
}