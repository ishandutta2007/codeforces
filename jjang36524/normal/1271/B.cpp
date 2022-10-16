#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char arr[210];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int M, K;
	cin >> M;
	int i;
	cin >> arr;
	int wcount = 0;
	for (i = 0; i < M; i++)
	{
		if (arr[i] == 'W')
			wcount++;
	}
	int ans = 0;
	vector<int>p;
	if ((M-wcount) % 2&&wcount%2)
		cout << -1;
	else if (!(wcount % 2))
	{
		for (i = 0; i < M - 1; i++)
		{
			if (arr[i] == 'W')
			{
				arr[i + 1] = arr[i + 1] == 'B' ? 'W' : 'B';
				p.push_back(i + 1);
				ans++;
			}

		}
		cout << ans << '\n';
		for (i = 0; i < ans; i++)
		{
			cout << p[i] << ' ';
		}
	}
	else
	{
		for (i = 0; i < M - 1; i++)
		{
			if (arr[i] == 'B')
			{
				arr[i + 1] = arr[i + 1] == 'B' ? 'W' : 'B';
				p.push_back(i + 1);
				ans++;
			}
				
		}
		cout << ans << '\n';
		for (i = 0; i < ans; i++)
		{
			cout << p[i] << ' ';
		}
	}
	
}