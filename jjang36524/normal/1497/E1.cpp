#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <set>
#include <math.h>
using namespace std;
set<int>s;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		s.clear();
		int N, M;
		cin >> N >> M;
		int i;
		int ans = 1;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			int na = 1;
			int j;
			int unt = sqrt(a);
			for (j = 2; j <= unt; j++)
			{
				int su = 0;
				while (a % j == 0)
				{
					a /= j;
					su++;
				}
				if (su % 2)
					na *= j;
			}
			if (a)
				na *= a;
			if(s.count(na))
			{
				s.clear();
				ans++;
			}
			s.insert(na);
		}
		cout << ans << '\n';
	}
}