#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int ans[N];
bool vis[N*2];
int a[N];
int cp[N];

void solve()
{
	int n;
	scanf("%d", &n);
	
	memset(ans, 0, n*4+50);
	memset(vis, 0, n*4+50);
	memset(a, 0, n*4+50);
	memset(cp, 0, n*4+50);
	int cnt = 0;
	
	for (int i = 1; i <= n; i ++ )
	{
		scanf("%d", &a[i]);
		if (!vis[a[i]])
		{
			ans[i] = a[i];
			vis[a[i]] = true;
			cp[a[i]] = i;
			cnt++;
		}
	}
	
	printf("%d\n", cnt);
	for (int i = 1, j = 1; i <= n; i ++ )
	{
		if (ans[i]) continue;
		while (cp[j] && j <= n) j ++;
		
		cp[j] = i;
		ans[i] = j;
		if (i == j)
		{
		
			swap(ans[cp[a[i]]], ans[i]);
			swap(cp[a[i]], cp[i]);
		}
		j ++;
	}
	for (int i = 1; i <= n; i ++ )
		printf("%d ", ans[i]);
	
	puts("");
	
	
	return ;
		
}

int main()
{
	int T;
	cin >> T;
	while(T -- )
	{
		solve();
	}
	return 0;
}