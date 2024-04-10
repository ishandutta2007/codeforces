#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1;
ll test,l,res,cur,ptr;
string str,tmp;
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
inline void solve()
{
	res=0,l=read(),cin>>str,cur=0;
	while(1)
	{
		tmp="";
		for(register int i=0;i<l;i++)
		{
			if(i&&str[i-1]=='A'&&str[i]=='P')
			{
				tmp+='A';
			}
			else
			{
				tmp+=str[i];
			}
		}
		if(str==tmp)
		{
			break;
		}
		str=tmp,res++;
	}
	printf("%d\n",res);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}