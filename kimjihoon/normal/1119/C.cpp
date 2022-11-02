#include <iostream>
using namespace std;

int n, m, a[509][509], b[509][509], p[509][509];

void fp(int x, int y)
{
	for (int i = y; i <= y + 1; i++)
		for (int j = x; j <= x + 1; j++)
			p[i][j] = (p[i][j] + 1) % 2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> b[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			p[i][j] = (bool)(a[i][j] != b[i][j]);
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 1; j++)
			if (p[i][j])
				fp(j, i);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (p[i][j]) {
				cout << "No" << '\n';
				return 0;
			}
	cout << "Yes" << '\n';
	return 0;
}