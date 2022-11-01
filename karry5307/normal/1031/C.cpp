#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll u,v,x;
vector<ll>s,t;
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
	u=read(),v=read();
	while((li)(x+1)*(x+2)/2<=u+v)
	{
		x++;
	}
	for(register int i=x;i;i--)
	{
		u>=i?s.push_back(i),u-=i:(t.push_back(i),v-=i);
	}
	printf("%d\n",s.size());
	for(register int i:s)
	{
		printf("%d ",i);
	}
	printf("\n%d\n",t.size());
	for(register int i:t)
	{
		printf("%d ",i);
	}
}