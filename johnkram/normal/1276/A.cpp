#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
char c[MAXN];
int t,n,i,m,a[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",c+1);
		n=strlen(c+1);
		for(m=0,i=1;i+2<=n;i++)if(c[i]=='t'&&c[i+1]=='w'&&c[i+2]=='o')
		{
			if(i+4<=n&&c[i+3]=='n'&&c[i+4]=='e')c[a[m++]=i+2]=0;
			else c[a[m++]=i+1]=0;
		}
		else if(c[i]=='o'&&c[i+1]=='n'&&c[i+2]=='e')c[a[m++]=i+1]=0;
		printf("%d\n",m);
		for(i=0;i<m;i++)printf("%d ",a[i]);
		puts("");
	}
	return 0;
}