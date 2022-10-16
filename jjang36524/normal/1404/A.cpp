#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		string s;
		cin >> N >> M >> s;
		int i;
		int z = 1,o = 0;
		int zz = 0;
		for (i = 0; i < M; i++)
		{
			int j;
			int val = -1;
			for (j = i; j < N; j += M)
			{
				if (s[j] == '?')
					continue;
				if (val >= 0)
				{
					if (s[j] - '0' != val)
						z = 0;
				}
				val = s[j] - '0';
			}
			if (val == 0)
				zz++;
			if (val == 1)
				o++;
		}
		if (zz > M / 2)
			z = 0;
		if (o > M / 2)
			z = 0;
		cout << (z ? "YES":"NO") << '\n';
	}
}