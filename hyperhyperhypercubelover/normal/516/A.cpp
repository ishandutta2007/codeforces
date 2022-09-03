#include<cstdio>

char a[20];
int d[10];

int r[100],rn;

void add(int x)
{
	int i,j,t;
    for(i=2;i<=x;i++)
	{
		t=i;
		for(j=2;t>1;j++)while(t%j==0)
		{
			d[j]++;
			t/=j;
		}
	}
}

void del(int x)
{
	int i,j,t;
    for(i=2;i<=x;i++)
	{
		t=i;
		for(j=2;t>1;j++)while(t%j==0)
		{
			d[j]--;
			t/=j;
		}
	}
}

int f(int x)
{
	int i;
	for(i=0;i<10;i++)
	{
		if(d[i]<0)return 0;
		if(d[i])break;
	}
    if(i==10)return 1;
	while(x>1)
	{
		if(x!=4&&x!=6&&x!=8)
		{
			del(x);
			if(f(x))
			{
				r[rn++]=x;
				return 1;
			}
			add(x);
		}
		x--;
	}
	return 0;
}

int main()
{
	int i,n;
	scanf("%d%s",&n,a);
    for(i=0;i<n;i++)add(a[i]-'0');
    f(7);
    while(rn--)printf("%d",r[rn]);
	return 0;
}