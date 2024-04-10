#include <bits/stdc++.h>
#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
int n,m,i,j,a[500005],top,cnt;
string s;
int main()
{
	scanf("%d%d",&n,&m);
	rdst(s,n+5);
	for (i=0;i<n;i++)
	{
		if (s[i]=='(')
		{
			if (cnt<m/2)
			{
				putchar('(');
				top++;
				cnt++;
			}
		}
		else
		{
			if (top>0)
			{
				putchar(')');
				top--;
			}
		}
	}
	return 0;
}