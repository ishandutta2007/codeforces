#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
int T;
int a, b, c, d;
string s;
int dp[401][201];
vector<int>arr;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		arr.clear();
		memset(dp, 1, sizeof(dp));
		int N;
		cin >> N;
		int i;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			arr.push_back(a);
		}
		int c = 1;
		queue<int>t;
		t.push(0);
		int ans = 0;
		while (t.size())
		{
			int a = t.front();
			t.pop();
			int oi = c;
			int bef = 0;
			while (c < N)
			{
				if (bef > arr[c])
					break;
				bef = arr[c];
				c++;
			}
			for (i = oi; i < c; i++)
			{
				t.push(a + 1);
			}
			ans = a;
		}
		cout << ans << '\n';
	}
}