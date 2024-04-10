#include <bits/stdc++.h>
using namespace std;

int pull[300005], arr[300005], occ[300005], n, m;
long long ans;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0;i < n;i++)
	{
		scanf("%d", arr+i);
		occ[arr[i]] = i;
	}
	for (int i = 0;i < m;i++)
	{
		int a, b; scanf("%d%d", &a, &b);
		if (occ[a] > occ[b])
			pull[occ[a]] = max(pull[occ[a]], occ[b]+1);
		else
			pull[occ[b]] = max(pull[occ[b]], occ[a]+1);
	}
	for (int i = 0, j = 0;i < n;i++)
	{
		j = max(j, pull[i]);
		ans += (i-j+1);
	}
	cout << ans << endl;
	return 0;
}