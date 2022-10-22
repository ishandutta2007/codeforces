#include<bits/stdc++.h>
using namespace std;
int t,n,i,a,b,c,x,y,z;
char d[105];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",d+1);
		n=strlen(d+1);
		a=b=c=x=y=z=0;
		for(i=1;i<=n;i++)if(d[i]>='a'&&d[i]<='z')
		{
			a=i;
			x++;
		}
		else if(d[i]>='A'&&d[i]<='Z')
		{
			b=i;
			y++;
		}
		else
		{
			c=i;
			z++;
		}
		if(a&&b&&c);
		else if(a&&b)d[x>1?a:b]='0';
		else if(b&&c)d[y>1?b:c]='a';
		else if(a&&c)d[x>1?a:c]='A';
		else if(a)
		{
			d[1]='0';
			d[2]='A';
		}
		else if(b)
		{
			d[1]='0';
			d[2]='a';
		}
		else
		{
			d[1]='A';
			d[2]='a';
		}
		puts(d+1);
	}
	return 0;
}