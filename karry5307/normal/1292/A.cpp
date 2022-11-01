#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=2e5+51;
ll cnt,qcnt,tot,x,y;
ll num[2][MAXN];
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
int main()
{
	cnt=read(),qcnt=read();
	for(register int i=0;i<qcnt;i++)
	{
		x=read()-1,y=read(),num[x][y]^=1;
		if(num[x][y])
		{
			for(register int j=y-1;j<=y+1;j++)
			{
				if(num[x^1][j])
				{
					tot++;
				}
			}
		}
		else
		{
			for(register int j=y-1;j<=y+1;j++)
			{
				if(num[x^1][j])
				{
					tot--;
				}
			}
		}
		puts(tot?"No":"Yes");
	}
}