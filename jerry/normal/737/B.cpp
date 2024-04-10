#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
int n, a, b, k;
char mp[200005];

int main()
{
	scanf("%d%d%d%d%s", &n, &a, &b, &k, mp);
	mp[n] = '1'; n++;
	int lst = -1;
	for (int i = 0;i < n;i++)
		if (mp[i] == '1')
			lst = i;
		else if ((i-lst)%b == 0)
			ans.push_back(i+1);
	printf("%d\n", ans.size()-a+1);
	for (int i = a-1;i < ans.size();i++) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}