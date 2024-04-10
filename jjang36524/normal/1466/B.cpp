#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int T, N;
set<int>t;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		vector<int>a;
		int i;
		int lastcnum = -1;
		int ans = 0;
		int has2 = 0;
		for (i = 0; i < N; i++)
		{
			int x;
			cin >> x;
			a.push_back(x);
			if (i == 0 || a[i] != a[i - 1])
			{
				ans++;
				if (i==0||a[i] - 1 != a[i - 1])
				{
					ans += has2;
					has2 = 0;
				}
			}
			else
			{
				has2 = 1;
			}
		}
		if (has2)
			ans++;
		cout << ans << '\n';
	}
}