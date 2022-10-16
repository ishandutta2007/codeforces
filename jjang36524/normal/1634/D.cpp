#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int T;
	cin >> T;
	while (T--)
	{
		vector<int>dis;
		int N;
		cin >> N;
		int i;
		queue<int>t;
		for (i = 0; i < N; i++)
		{
			t.push(i+1);
		}
		while (t.size() > 2)
		{
			vector<int>c;
			int j;
			for (j = 0; j < 4; j++)
			{
				c.push_back(t.front());
				t.pop();
			}
			vector<pair<int,int>>res;
			for (j = 0; j < 4; j++)
			{
				cout << '?';
				int k;
				for (k = 1; k <= 3; k++)
				{
					cout << ' ' << c[(j + k) % 4];
				}
				cout << '\n';
				cout.flush();
				int r;
				cin >> r;
				if (r == -1)
					return 0;
				res.push_back({ r,j });
			}
			sort(res.begin(), res.end());
			int l;
			for (l = 0; l < 4; l++)
			{
				if (l<2)
				{
					t.push(c[res[l].second]);
				}
				else
				{
					dis.push_back(c[res[l].second]);
				}
			}
			if (t.size() == 3)
			{
				t.push(dis.back());
				dis.pop_back();
			}
		}
		if (t.size() == 1)
		{
			cout << "! ";
			cout << t.front() << ' ' << t.front() << '\n';
			cout.flush();
		}
		else
		{
			cout << "! ";
			cout << t.front() << ' ';
			t.pop();
			cout << t.front() << '\n';
			cout.flush();
		}
	}
}