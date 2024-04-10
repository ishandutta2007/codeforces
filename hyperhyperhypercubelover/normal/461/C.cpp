#include<cstdio>

int BIT[111111];

void upd(int x,int y)
{
	while(x<111111)
	{
		BIT[x]+=y;
		x+=x&-x;
	}
}

int get(int x)
{
	int y=0;
	while(x)
	{
		y+=BIT[x];
		x-=x&-x;
	}
	return y;
}

int main()
{
	int rev;
	int s,e;
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    s=0;e=n;rev=0;
    for(i=1;i<=n;i++)upd(i,1);
    while(m--)
	{
		scanf("%d",&i);
		if(i==2)
		{
            scanf("%d%d",&i,&j);
            if(rev)printf("%d\n",get(e-i)-get(e-j));
            else printf("%d\n",get(j+s)-get(i+s));
		}
		else
		{
			scanf("%d",&j);
            if(rev)j=e-j;
            else j=j+s;
            if(j+j<s+e)
			{
                for(i=0;j-i>s;i++)upd(j+i+1,get(j-i)-get(j-i-1));
                s=j;
                rev=0;
			}
			else
			{
                for(i=0;j+i<e;i++)upd(j-i,get(j+i+1)-get(j+i));
                e=j;
                rev=1;
			}
		}
	}
}