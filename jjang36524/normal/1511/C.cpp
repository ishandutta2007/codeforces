#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#define int long long
using namespace std;
vector<int>li[51];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, Q;
	cin >> N >> Q;
	int i;
	for (i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		li[a].push_back(i);
	}
	for (i = 0; i < Q; i++)
	{
		int x;
		cin >> x;
		int j;
		int ans = 1;
		for (j = 1; j <= 50; j++)
		{
			ans +=lower_bound(li[j].begin(), li[j].end(), li[x][0])-li[j].begin();
		}
		cout << ans << ' ';
		li[x][0] = -i-1;
	}
}