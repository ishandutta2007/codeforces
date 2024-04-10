#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
int N, M,a,b;
signed main()
{
	int T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N >> M >> a >> b;
		if (N * a != M * b)
		{
			cout << "NO" << '\n';
		}
		else
		{
			cout << "YES" << '\n';
			int i,j;
			for (i = 0; i < N; i++)
			{
				for (j = 0; j < M; j++)
				{
					int p = M*i / N;
					if (j >= p && j < p + a)
						cout << 1;
					else if (j < p + a - M)
						cout << 1;
					else
						cout << 0;
				}
				cout << '\n';
			}
		}
	}
}