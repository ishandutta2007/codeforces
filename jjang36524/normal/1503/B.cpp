#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int arr[101][101];
int col[201];
int us[201];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	using namespace std;
	int N;
	cin >> N;
	int i,j;
	vector<pair<int, int>>zp, op;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if ((i + j) % 2)
				op.push_back({ i + 1,j + 1 });
			else
				zp.push_back({ i + 1,j + 1 });
		}
	}
	for (i = 0; i < N * N; i++)
	{
		int a;
		cin >> a;
		if (a == 1)
		{
			if (zp.size())
			{
				cout << 2 << ' ' << zp.back().first << ' ' << zp.back().second << '\n';
				cout.flush();
				zp.pop_back();
			}
			else
			{
				cout << 3 << ' ' << op.back().first << ' ' << op.back().second << '\n';
				cout.flush();
				op.pop_back();
			}
		}
		else
		{
			if (op.size())
			{
				cout << 1 << ' ' << op.back().first << ' ' << op.back().second << '\n';
				cout.flush();
				op.pop_back();
			}
			else
			{
				cout << (a==3?2:3) << ' ' << zp.back().first << ' ' << zp.back().second << '\n';
				cout.flush();
				zp.pop_back();
			}
		}
	}
}