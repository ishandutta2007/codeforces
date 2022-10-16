#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#define int long long
using namespace std;
int T, a, b, c, d, e, f;
priority_queue<int,vector<int>,greater<int>>t[200100];
int arr[200100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> a;
		t[a].push(0);
		int no = a;
		int na = 1;
		while (no)
		{
			int po = t[no].top();
			t[no].pop();
			int pl = (no-1) / 2;
			arr[po + pl] = na;
			na++;
			t[pl].push(po);
			t[no / 2].push(po + pl + 1);
			while (t[no].empty())
				no--;
		}
		int i;
		for (i = 0; i < a; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
}