#include <bits/stdc++.h>
using namespace std;

set <string> s;

int main()
{
	int n;
	scanf("%d",&n);
	string t;
	for (int i=0;i<n;i++)
	{
		cin >> t;
		if (s.find(t)==s.end())
		{
			puts("NO");
			s.insert(t);
		}
		else
			puts("YES");
	}
	return 0;
}