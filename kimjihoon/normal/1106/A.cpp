#include <iostream>
#include <string>
using namespace std;

string s[509];
int dx[4] = { -1, 1, 1, -1 }, dy[4] = { 1, 1, -1, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	int ans = 0;
	for (int i = 1; i < n - 1; i++)
		for (int j = 1; j < n - 1; j++) {
			if (s[i][j] != 'X') continue;
			bool f = true;
			for (int k = 0; k < 4; k++)
				if (s[i + dy[k]][j + dx[k]] != 'X') {
					f = false;
					break;
				}
			if (f)
				ans++;
		}
	cout << ans << '\n';
	return 0;
}