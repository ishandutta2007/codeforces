#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
int n;

int f(int x) { return x+(n+x-1)/x; }

int main()
{
	scanf("%d", &n);
	int len = 1, best = f(len);
	for (int i = 2;i <= n;i++)
	{
		int alt = f(i);
		if (alt < best)
		{
			len = i;
			best = alt;
		}
	}
	for (int i = n/len*len;i >= 0;i-=len) for (int j = i;j < i+len && j < n;j++) ans.push_back(j+1);
	for (int i = 0;i < n;i++) printf("%d%c", ans[i], " \n"[i+1==n]);
	return 0;
}