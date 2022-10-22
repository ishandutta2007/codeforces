#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,i,j;
char c[105];
int main()
{
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%s",c);
		for(j=0;j<m;j++)if(c[j]=='.')if(i+j&1)c[j]='W';
		else c[j]='B';
		printf("%s\n",c);
	}
	return 0;
}