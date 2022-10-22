#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,a[105],i,j;
char s[105];
int main()
{
	scanf("%d",&n);
	for(i=0;i+1<n;i++)scanf("%d",a+i);
	scanf("%d\n",a+i);
	for(i=0;i<n;i++)
	{
		gets(s);
		m=strlen(s);
		for(j=0;j<m;j++)if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'||s[j]=='y')a[i]--;
		if(a[i])break;
	}
	if(i==n)puts("YES");
	else puts("NO");
	return 0;
}