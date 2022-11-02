#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=6e5+51;
stack<ll>st;
ll cnt,tot,x,y,res;
ll num[MAXN];
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
	cnt=read();
	for(register int i=0;i<cnt;i++)
	{
		num[i]=read();
		while(st.size()>=2)
		{
			x=st.top(),st.pop(),y=st.top();
			if(y>=x&&x<=num[i])
			{
				res+=min(y,num[i]);
			}
			else
			{
				st.push(x);
				break;
			}
		}
		st.push(num[i]);
	}
	while(!st.empty())
	{
		num[tot++]=st.top(),st.pop();
	}
	sort(num,num+tot);
	for(register int i=0;i<tot-2;i++)
	{
		res+=num[i];
	}
	printf("%lld\n",res);
}