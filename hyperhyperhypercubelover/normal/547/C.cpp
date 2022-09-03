#include<cstdio>

int a[222222];
int v[222222];
int p[555555];
int q[555555];
int c[555555];
int t[22],tn;

void fac(int x)
{
	tn=0;
	int i;
	for(i=2;i*i<=x;i++)if(x%i==0)
	{
		t[tn++]=i;
		while(x%i==0)x/=i;
	}
	if(x>1)t[tn++]=x;
}

int main()
{
	long long now=0,cnt=0;
	int i,j,n,m,temp;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<555555;i++)p[i]=1;
    for(i=2;i<555555;i++)if(!q[i])for(j=i;j<555555;j+=i)
	{
		p[j]=-p[j];
		q[j]=1;
	}
    while(m--)
	{
		scanf("%d",&i);
		if(!v[i])
		{
			v[i]=1;
			cnt++;
			fac(a[i]);
			for(i=1;i<(1<<tn);i++)
			{
				temp=1;
				for(j=0;j<tn;j++)if((i>>j)&1)temp*=t[j];
				now+=1LL*p[temp]*c[temp]*(c[temp]-1)/2;
				c[temp]++;
				now-=1LL*p[temp]*c[temp]*(c[temp]-1)/2;
			}
			printf("%I64d\n",cnt*(cnt-1)/2-now);
		}
		else
		{
			v[i]=0;
			cnt--;
			fac(a[i]);
			for(i=1;i<(1<<tn);i++)
			{
				temp=1;
				for(j=0;j<tn;j++)if((i>>j)&1)temp*=t[j];
				now+=1LL*p[temp]*c[temp]*(c[temp]-1)/2;
				c[temp]--;
				now-=1LL*p[temp]*c[temp]*(c[temp]-1)/2;
			}
			printf("%I64d\n",cnt*(cnt-1)/2-now);
		}
	}
}