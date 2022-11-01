#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e3+51;
ll n,x,y;
ll r[MAXN][MAXN];
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
	n=read(),x=4,y=1;
	if(n<=2)
	{
		return puts("-1"),0;
	}
	for(register int i=1;i<=n*n-9;i++)
	{
		r[x][y]=i,max(x,y)&1?y==1?x++:(x<y?x++:y--):x==1?y++:(x>y?y++:x--);
	}
	r[1][1]=n*n-8,r[1][2]=n*n-2,r[1][3]=n*n;
	r[2][1]=n*n-6,r[2][2]=n*n-7,r[2][3]=n*n-4;
	r[3][1]=n*n-5,r[3][2]=n*n-1,r[3][3]=n*n-3;
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			printf("%d ",r[i][j]);
		}
		puts("");
	}
}