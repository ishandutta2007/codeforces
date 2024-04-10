#include<bits/stdc++.h>
using namespace std;
typedef int ll;
queue<ll>q;
ll num,need,size,top;
ll mp[41];
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
	num=read(),need=read();
	for(register int i=0;i<31;i++)
	{
		if(num&(1<<i))
		{
			if(i)
			{
				q.push(i);
			}
			mp[i]++,size++;
		}
	}
	if(size>need)
	{
		puts("NO");
		return 0;
	}
	while(size<need&&!q.empty())
	{
		top=q.front(),q.pop();
		mp[top]--,mp[top-1]+=2,size++;
		if(top!=1)
		{
			q.push(top-1),q.push(top-1);
		}
	}
	if(size!=need)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for(register int i=0;i<31;i++)
	{
		for(register int j=0;j<mp[i];j++)
		{
			printf("%d ",1<<i);
		}
	}
}