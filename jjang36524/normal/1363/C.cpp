#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
#define int long long
int N, M, T, a, b, c, d;
string s;
int arr[1010];
vector<int>t[1010];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		memset(arr, 0, sizeof(arr));
		int i;
		cin >> N>>M;
		for (i = 1; i <= N; i++)
		{
			t[i].clear();
		}
		for (i = 1; i < N; i++)
		{
			int x, y;
			cin >> x >> y;
			t[x].push_back(y);
			t[y].push_back(x);
		}
		int ma = 0;
		if (t[M].size() <= 1)
			cout << "Ayush" << '\n';
		else
			cout << (((N+1) % 2) ? "Ayush" : "Ashish") << '\n';
	}
}