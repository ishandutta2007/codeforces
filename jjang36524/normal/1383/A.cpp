#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int N, M, T;
int arr[1001000];
string a, b;
vector<int>t[20];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N >> a >> b;
		int i;
		int ans = 0;
		for (i = 0; i < 20; i++)
			t[i].clear();
		for (i = 0; i < N; i++)
		{
			if (a[i] > b[i])
			{
				cout << -1 << '\n';
				goto T;
			}
			else if (a[i] != b[i])
			{
				t[a[i] - 'a'].push_back(b[i] - 'a');
			}
		}

		for (i = 0; i < 20; i++)
		{
			if (t[i].size())
				ans++;
			int j;
			int mi = 19;
			for (j = 0; j < t[i].size(); j++)
			{
				mi = min(mi, t[i][j]);
			}
			for (j = 0; j < t[i].size(); j++)
			{
				if (t[i][j] != mi)
					t[mi].push_back(t[i][j]);
			}
		}
		cout << ans << '\n';
	T:
		int dy;
	}
}