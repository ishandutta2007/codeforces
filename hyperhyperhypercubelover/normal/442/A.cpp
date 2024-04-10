#include<cstdio>

char str[100];
int a[100];
int b[100];

int d[5][5];

int p[5];
int q[5];

int main()
{
	int i,j,k,l,n,max=987654321,x,y;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",str);
		if(str[0]=='R')a[i]=0;
		if(str[0]=='G')a[i]=1;
		if(str[0]=='B')a[i]=2;
		if(str[0]=='Y')a[i]=3;
		if(str[0]=='W')a[i]=4;
		if(str[1]=='1')b[i]=0;
		if(str[1]=='2')b[i]=1;
		if(str[1]=='3')b[i]=2;
		if(str[1]=='4')b[i]=3;
		if(str[1]=='5')b[i]=4;
		d[a[i]][b[i]]++;
	}
	for(i=0;i<32;i++)
	{
		for(k=0;k<5;k++)p[k]=(i>>k)&1;
		for(j=0;j<32;j++)
		{
			for(k=0;k<5;k++)q[k]=(j>>k)&1;
			for(k=0;k<n;k++)
			{
				l=0;
				for(x=0;x<5;x++)if(x==a[k]||(p[a[k]]==0&&p[x]==0))for(y=0;y<5;y++)if(y==b[k]||(q[b[k]]==0&&q[y]==0))if(d[x][y])l++;
				if(l>1)break;
			}
			if(k==n)
			{
				l=0;
				for(x=0;x<5;x++)l+=p[x];
				for(y=0;y<5;y++)l+=q[y];
				if(l<max)max=l;
			}
		}
	}
	printf("%d",max);
	return 0;
}