#include <iostream>
using namespace std;

long long d[200009][3], s[3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; long long l, r; cin >> n >> l >> r;
	l--;
	s[0] = s[1] = s[2] = r / 3 - l / 3;
	for (int i = 1; i <= r % 3; i++)
		s[i]++;
	for (int i = 1; i <= l % 3; i++)
		s[i]--;
	d[0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			for (int t = 0; t < 3; t++)
				d[i + 1][(j + t) % 3] = (d[i + 1][(j + t) % 3] + d[i][j] * s[t]) % 1000000007;
	cout << d[n][0] << '\n';
	return 0;
}