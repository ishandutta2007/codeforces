#include <bits/stdc++.h>
using namespace std;

char a[1005], b[1005];
map<char, char> ans;
map<char, char> mp;

void add(char x, char y)
{
	auto it = mp.find(x);
	if (it != mp.end())
	{
		if (it->second == y) return;
		printf("-1\n");
		exit(0);
	}
	mp[x] = y;
}

int main()
{
	scanf("%s%s", a, b);
	for (int i = 0;a[i];i++)
	{
		add(a[i], b[i]);
		add(b[i], a[i]);
	}
	for (auto it = mp.begin();it != mp.end();it++) if (it->first < it->second) ans[it->first] = it->second;
	printf("%d\n", ans.size());
	for (auto it = ans.begin();it != ans.end();it++) printf("%c %c\n", it->first, it->second);
	return 0;
}