#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define int long long
vector<int>arr;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c, d, N;
	cin >> a >> b >> c >> d >> N;
	string s;
	cin >> s;
	int st = 0;
	int en = 1LL << 60;
	while (st != en)
	{
		int m = (st + en) / 2;
		int i;
		int nc = c;
		int nd = d;
		for (i = 0; i < N; i++)
		{
			if (s[i] == 'U')
			{
				nd -= m / N + (i < (m % N));
			}
			if (s[i] == 'D')
			{
				nd += m / N + (i < (m % N));
			}
			if (s[i] == 'R')
			{
				nc -= m / N + (i < (m % N));

			}
			if (s[i] == 'L')
			{
				nc += m / N + (i < (m % N));
			}
		}
		if (abs(a - nc) + abs(b - nd) <= m)
		{
			en = m;
		}
		else
			st = m + 1;
	}
	if (st == 1LL << 60)
		cout << -1;
	else
		cout << st;
}