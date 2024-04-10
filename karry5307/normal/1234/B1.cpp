#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1e5+51;
unordered_map<ll,ll>mp;
deque<ll>q;
ll cnt,sz,num,szz;
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
	cnt=read(),sz=read();
	for(register int i=0;i<cnt;i++)
	{
		num=read();
		if(!mp[num])
		{
			if(szz==sz)
			{
				mp[q.back()]=0,q.pop_back(),szz--;
			}
			mp[num]=1,q.push_front(num),szz++;
		}
	}
	printf("%d\n",szz);
	for(register int i=0;i<szz;i++)
	{
		printf("%d ",q[i]);
	}
}