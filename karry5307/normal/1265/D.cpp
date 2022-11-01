#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1e5+51;
ll pos;
ll x[4],y[4],res[MAXN];
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
} 
inline bool check(ll pos)
{
	for(register int i=1;i<=x[0]+x[1]+x[2]+x[3];i++)
	{
		y[pos]--,res[i]=pos;
		if(i==x[0]+x[1]+x[2]+x[3])
		{
			return 1;
		}
		if(pos==0)
		{
			if(!y[1])
			{
				return 0;
			}
			pos++;
			continue;
		}
		if(pos==1)
		{
			if(y[0])
			{
				pos--;
			}
			else
			{
				if(y[2])
				{
					pos++;	
				}	
				else
				{
					return 0;
				}
			}
			continue;			
		}
		if(pos==2)
		{
			if(y[1])
			{
				pos--;
			}
			else
			{
				if(y[3])
				{
					pos++;	
				}	
				else
				{
					return 0;
				}
			}	
			continue;		
		}
		if(pos==3)
		{
			if(!y[2])
			{
				return 0;
			}
			pos--;
			continue;
		}
	}
}
int main()
{
	x[0]=read(),x[1]=read(),x[2]=read(),x[3]=read();
	for(register int i=0;i<4;i++)
	{
		for(register int j=0;j<4;j++)
		{
			y[j]=x[j];
		}
		if(y[i]>0)
		{
			if(check(i))
			{
				puts("YES");
				for(register int j=1;j<=x[0]+x[1]+x[2]+x[3];j++)
				{
					printf("%d ",res[j]);
				}
				return puts(""),0;
			}
		}
	}
	puts("NO");
}