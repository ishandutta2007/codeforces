#include <iostream>
#include <algorithm>
#include <math.h>
#define int long long
using namespace std;
int T, N, M;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int i;
		pair<int, int>ar = { N-1,1 };
		for (i = 2; i <= sqrt(N); i++)
		{
			if (N % i == 0)
			{
				ar = min(make_pair( (N - i),i ),ar);
				i = N / i;
				ar = min(make_pair((N - i), i), ar);
				i = N / i;
			}
		}
		cout << ar.first << ' ' << ar.second << '\n';
	}
}