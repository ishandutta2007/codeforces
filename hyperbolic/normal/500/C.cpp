#include <stdio.h>
int x[510],y[1010],z[510],check[510];
int main()
{
	int a,b,i,j,k,count=0,s,t=1;
	scanf("%d%d",&a,&b);
	for(i=1;i<=a;i++) scanf("%d",&x[i]);
	for(i=1;i<=b;i++) scanf("%d",&y[i]);
	for(i=1;i<=b;i++)
	{
		if(check[y[i]]==0)
		{
			check[y[i]]=1;
			z[t++]=y[i];
		}
	}
	for(i=1;i<=b;i++)
	{
		s=0;
		for(j=1;j<t;j++)
		{
			if(z[j]==y[i])
			{
				count+=s;
				for(k=j;k>1;k--) z[k]=z[k-1];
				z[1]=y[i];
				break;
			}
			else s+=x[z[j]];
		}
	}
	printf("%d",count);
}