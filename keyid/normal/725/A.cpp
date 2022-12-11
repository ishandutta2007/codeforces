#include <bits/stdc++.h>
using namespace std;

const int MAXL=200005;

char s[MAXL];

int main()
{
	int n,cnt=0;
	scanf("%d%s",&n,s);
	bool f=false;
	for (int i=0;i<n;i++)
	{
		if (s[i]=='<')
		{
			if (f)
				cnt++;
		}
		else
			f=true;
	}
	f=false;
	for (int i=n-1;i>=0;i--)
	{
		if (s[i]=='>')
		{
			if (f)
				cnt++;
		}
		else
			f=true;
	}
	printf("%d",n-cnt);
	return 0;
}