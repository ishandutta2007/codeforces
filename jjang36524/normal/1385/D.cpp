#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int N, T, a, b, c, d;
char arr[200100];
int dfs(int s, int e,char p)
{
	if (s == e)
	{
		return p != arr[s];
	}
	int m = (s + e) / 2;
	int i;
	int fan=dfs(m+1,e,p+1),san = dfs(s,m,p+1);
	for (i = s; i <= m; i++)
	{
		fan += arr[i] != p;
	}
	for (i = m+1; i <= e; i++)
	{
		san += arr[i] != p;
	}
	return min(fan, san);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		int x;
		cin >> x;
		cin >> arr;
		int l = strlen(arr);
		cout << dfs(0, l - 1, 'a')<<'\n';
	}
}