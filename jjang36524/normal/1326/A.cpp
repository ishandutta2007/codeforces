#include <algorithm>
#include <iostream>
#define int long long
using namespace std;
int N, K;
int ord[200100];
int rev[200100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int curmax = 0;
	int i;
	for (i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		if (a == 1)
			cout << -1 << '\n';
		else
		{
			int firstc = a * 2 + 7;
			int j;
			for (j = 0; j < a; j++)
			{
				if (j == 0)
					cout << ((firstc % 9) ? 2 : 4);
				else if (j + 1 == a)
					cout << 9;
				else
					cout << 2;
			}
			cout << '\n';
		}
	}
}