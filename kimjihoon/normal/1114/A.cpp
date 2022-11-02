#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int p[3], g[3];
	for (int i = 0; i < 3; i++)
		cin >> p[i];
	for (int i = 0; i < 3; i++)
		cin >> g[i];
	if (p[0] > g[0]) {
		cout << "NO" << '\n';
		return 0;
	}
	g[0] -= p[0];
	if (g[0] + g[1] < p[1] || g[0] + g[1] + g[2] - p[1] < p[2]) {
		cout << "NO" << '\n';
		return 0;
	}
	cout << "YES" << '\n';
	return 0;
}