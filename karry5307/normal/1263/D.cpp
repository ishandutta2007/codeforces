#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=2e5+51;
set<ll>st;
ll cnt,fx,fy;
ll ffa[MAXN],t[128];
string str[MAXN];
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
inline ll find(ll x)
{
	return ffa[x]==x?x:ffa[x]=find(ffa[x]);
}
int main()
{
	cnt=read();
	for(register int i=1;i<=cnt;i++)
	{
		cin>>str[i];
		ffa[i]=i;
	}
	for(register int i=0;i<str[1].length();i++)
	{
		t[str[1][i]]=1;
	}
	for(register int i=2;i<=cnt;i++)
	{
		for(register int j=0;j<str[i].length();j++)
		{
			if(t[str[i][j]])
			{
				fx=find(i),fy=find(t[str[i][j]]);
				if(fx!=fy)
				{
					ffa[fy]=fx;
				}
			} 
			else
			{
				t[str[i][j]]=i;
			}
		}
	}
	for(register int i=1;i<=cnt;i++)
	{
		st.insert(find(i)); 
	}
	printf("%d\n",st.size());
}