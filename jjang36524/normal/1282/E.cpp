#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define int long long
using namespace std;
int T;
int nodeapp[100100];
vector<int>hasthing[100100];
int input[100100][3];
vector<int>order;
int revorder[100100];
vector<int>order2;
int pos[100100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		int i;
		int N;
		cin >> N;
		order.clear();
		order2.clear();
		for (i = 1; i <= N; i++)
		{
			hasthing[i].clear();
			nodeapp[i] = 0;
			revorder[i] = 0;
			pos[i] = 0;
		}
		for (i = 1; i <= N-2; i++)
		{
			cin >> input[i][0] >> input[i][1] >> input[i][2];
			int j;
			for (j = 0; j < 3; j++)
			{
				nodeapp[input[i][j]]++;
				hasthing[input[i][j]].push_back(i);
			}
		}
		queue<int>merrychristmas;
		for (i = 1; i <= N; i++)
		{
			if (nodeapp[i] == 1)
				merrychristmas.push(i);
		}
		while (merrychristmas.size())
		{
			int now = merrychristmas.front();
			merrychristmas.pop();
			order2.push_back(now);
			int j;
			for (j = 0; j < hasthing[now].size(); j++)
			{
				if (revorder[hasthing[now][j]])
					continue;
				int k;
				for (k = 0; k < 3; k++)
				{
					nodeapp[input[hasthing[now][j]][k]]--;
					if (nodeapp[input[hasthing[now][j]][k]]==1)
						merrychristmas.push(input[hasthing[now][j]][k]);
				}
				order.push_back(hasthing[now][j]);
				revorder[hasthing[now][j]] = 1;
			}
		}
		for (i = N - 1; i >= N - 3; i--)
		{
			pos[order2[i]] = order2[N - 1 - (N - i) % 3];
		}
		for (i >= N - 4; i >= 0; i--)
		{
			int fi=0, se, no;
			int j;
			for (j = 0; j < 3; j++)
			{
				if (input[order[i]][j] != order2[i])
				{
					if (fi)
						se = input[order[i]][j];
					else
						fi = input[order[i]][j];
				}
				else
				{
					no = order2[i];
				}
			}
			if (pos[fi] != se)
				swap(fi, se);
			pos[fi] = no;
			pos[no] = se;
		}
		int nowpos = pos[1];
		while (nowpos != 1)
		{
			cout << nowpos << ' ';
			nowpos = pos[nowpos];
		}
		cout <<1<< '\n';
		for (i = 0; i < N - 2; i++)
		{
			cout << order[i]<<' ';
		}
		cout << '\n';
	}
}