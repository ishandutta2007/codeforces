#include <bits/stdc++.h>
using namespace std;

bool check()
{
	int n;
	scanf("%d",&n);
	char op[10];
	int t,d=0;
	while (n--)
	{
		scanf("%d%s",&t,op);
		if (d==0)
		{
			if (op[0]!='S') return false;
		}
		else if (d==20000)
		{
			if (op[0]!='N') return false;
		}
		if (op[0]=='S') d+=t;
		else if (op[0]=='N') d-=t;
		if (d<0||d>20000) return false;
	}
	return d==0;
}

int main()
{
	puts(check()?"YES":"NO");
	return 0;
}