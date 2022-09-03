#include<cstdio>
#include<cstring>

char a[100];

int main()
{
	int i,n,m;
	scanf("%s%d",a,&m);
	n=strlen(a);
	for(i=0;i<n;i++)if(a[i]<'a')a[i]+='a'-'A';
	for(i=0;i<n;i++)
	{
		if(a[i]<m+97)
		{
			a[i]-='a'-'A';
		}
	}
	puts(a);
}