#include <bits/stdc++.h>
using namespace std;

string ans, tmp;
bool a, b;
int n;

void yer()
{
	printf("YES\n");
	exit(0);
}

int main()
{
	cin >> ans >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> tmp;
		if (tmp == ans) yer();
		if (tmp[1] == ans[0]) b = true;
		if (tmp[0] == ans[1]) a = true;
	}
	if (a && b) yer();
	printf("NO\n");
	return 0;
}