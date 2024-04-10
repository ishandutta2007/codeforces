#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int	n; string s;
		cin >> n >> s;
		if (n == 2 && s[0] >= s[1])
			cout << "NO" << '\n';
		else {
			cout << "YES" << '\n';
			cout << 2 << '\n';
			cout << s[0] << " ";
			for (int i = 1; i < n; i++)
				cout << s[i];
			cout << '\n';
		}
	}
	return 0;
}