#include<cstdio>
#include<algorithm>

int a[5000],an;
int b[5000],bn;
int c[5000],cn;

int main()
{
	int i,n,t;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
		if(t==1)a[an++]=i;
		if(t==2)b[bn++]=i;
		if(t==3)c[cn++]=i;
	}
	printf("%d\n",std::min(an,std::min(bn,cn)));
	for(i=0;i<std::min(an,std::min(bn,cn));i++)printf("%d %d %d\n",a[i],b[i],c[i]);
}