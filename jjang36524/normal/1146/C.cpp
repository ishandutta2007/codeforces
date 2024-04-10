#include <iostream>
#include <algorithm>
using namespace std;
int T;
int N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int treeN = 1, c;
		for (c = 0; treeN < N; c++, treeN *= 2);
		int i;
		int ans = 0;
		for (i = 0; i< c;i++)
		{
			int n1 = 0;
			int j;
			for (j = 0; j < N; j++)
			{
				if (j % (1 << (i + 1)) >= (1 << i))
					n1++;
			}
			cout << n1 << ' ' << N - n1<<' ';
			for (j = 0; j < N; j++)
			{
				if (j % (1 << (i + 1)) >= (1 << i))
					cout << j + 1 << ' ';
			}
			for (j = 0; j < N; j++)
			{
				if (j % (1 << (i + 1))< (1 << i))
					cout << j + 1 << ' ';
			}
			cout << '\n';
			cout.flush();
			int t;
			cin >> t;
			if (t == -1)
				return 0;
			ans = max(ans, t);
		}
		cout << -1 << ' ' << ans << '\n';
		cout.flush();
	}
 }