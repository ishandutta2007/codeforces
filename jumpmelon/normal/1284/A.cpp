#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30, MAXM = 20;
string S[MAXN], T[MAXM];

int main()
{
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> S[i];
	for (int i = 0; i < m; i++)
		cin >> T[i];
	int q;
	cin >> q;
	while (q--)
	{
		int y;
		cin >> y;
		y--;
		cout << S[y % n] + T[y % m] << '\n';
	}
	return 0;
}