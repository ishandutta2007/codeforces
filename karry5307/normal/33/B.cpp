#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,m,u,v,w,res,rr;
ll dist[27][27];
char s[MAXN],t[MAXN],r[MAXN],ux[2],vx[2];
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
	memset(dist,0x3f,sizeof(dist)),scanf("%s%s",s+1,t+1),m=read();
	if((n=strlen(s+1))!=strlen(t+1))
	{
		return puts("-1"),0;
	}
	for(register int i=1;i<=26;i++)
	{
		dist[i][i]=0;
	}
	for(register int i=1;i<=m;i++)
	{
		scanf("%s%s",ux+1,vx+1),w=read(),u=ux[1]-'a'+1,v=vx[1]-'a'+1;
		dist[u][v]=min(dist[u][v],w);
	}
	for(register int k=1;k<=26;k++)
	{
		for(register int i=1;i<=26;i++)
		{
			for(register int j=1;j<=26;j++)
			{
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	for(register int i=1;i<=n;i++)
	{
		u=s[i]-'a'+1,v=t[i]-'a'+1,rr=0x3f3f3f3f;
		for(register int j=1;j<=26;j++)
		{
			if(rr>=dist[u][j]+dist[v][j])
			{
				rr=dist[u][j]+dist[v][j],r[i]=j+'a'-1;
			}
		}
		if(rr==0x3f3f3f3f)
		{
			return puts("-1"),0;
		}
		res+=rr;
	}
	printf("%d\n%s",res,r+1);
}