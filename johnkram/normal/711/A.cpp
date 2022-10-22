#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char s[1005][10];
int n,i;
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%s",s[i]);
	for(i=0;i<n;i++)
	{
		if(s[i][0]=='O'&&s[i][1]=='O')
		{
			s[i][0]=s[i][1]='+';
			break;
		}
		if(s[i][3]=='O'&&s[i][4]=='O')
		{
			s[i][3]=s[i][4]='+';
			break;
		}
	}
	if(i==n)puts("NO");
	else for(puts("YES"),i=0;i<n;i++)puts(s[i]);
	return 0;
}