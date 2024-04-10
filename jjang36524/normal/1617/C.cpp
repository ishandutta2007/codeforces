#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int gcd(int n, int m)
{
	return m ? gcd(m, n % m) : n;
}
int vis[100100];
int main()
{
	int T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		int i;
		vector<int>t;
		for (i = 1; i <= N; i++)
			vis[i] = 0;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			if (a > N||vis[a])
				t.push_back(a);
			else
			{
				vis[a] = 1;
			}
		}
		sort(t.begin(), t.end());
		int c = 0;
		for (i = 1; i <= N; i++)
		{
			if (vis[i] == 0)
			{
				if ((t[c] - 1) / 2 < i)
				{
					cout << -1;
					break;
				}
				c++;
			}
		}
		if (i > N)
			cout << t.size();
		cout << '\n';
	}
}