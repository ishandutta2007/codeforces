#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	int t = (n - 11) / 2, c = 0, p = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '8') p++;
		else c++;
		if (c > t) break;
	}
	if (p - t > 0) cout << "YES" << '\n';
	else cout << "NO" << '\n';
	return 0;
}