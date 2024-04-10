#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
map<string,ll>mp;
ll cnt,ccnt,res,op,sz,ord;
string str;
ll mat[45][45],indSet[MAXN],tmp[MAXN],szz[MAXN];
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
inline void dfs(ll cur,ll sz)
{
	for(register int i=cur+1;i<=ccnt;i++)
	{
		if(szz[i]+sz<=res)
		{
			return;
		}
		if(!mat[cur][i])
		{
			bool flag=1;
			for(register int j=0;j<sz;j++)
			{
				if(mat[indSet[j]][i])
				{
					flag=0;
					break;
				}
			}
			if(flag)
			{
				indSet[sz]=i,dfs(i,sz+1);
			}
		}
	}
	res=max(res,sz);
}
inline void calcIndSet()
{
	res=1;
	for(register int i=ccnt;i;i--)
	{
		indSet[0]=i,dfs(i,1),szz[i]=res;
	}
}
int main()
{
	cnt=read(),ccnt=read();
	for(register int i=0;i<cnt;i++)
	{
		op=read();
		if(i==1&&op==1)
		{
			continue;
		}
		if(op==2)
		{
			cin>>str;
			if(mp.find(str)!=mp.end())
			{
				tmp[++sz]=mp[str];
			}
			else
			{
				tmp[++sz]=(mp[str]=++ord);
			}
		}
		else
		{
			for(register int i=1;i<=sz;i++)
			{
				for(register int j=i+1;j<=sz;j++)
				{
					if(tmp[i]^tmp[j])
					{
						mat[tmp[i]][tmp[j]]=mat[tmp[j]][tmp[i]]=1;
					}
				}
			}
			sz=0;
		}
	}
	for(register int i=1;i<=sz;i++)
	{
		for(register int j=i+1;j<=sz;j++)
		{
			if(tmp[i]^tmp[j])
			{
				mat[tmp[i]][tmp[j]]=mat[tmp[j]][tmp[i]]=1;
			}
		}
	}
	calcIndSet();
	printf("%d\n",res);
}