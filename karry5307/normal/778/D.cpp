#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef pair<ll,ll> pii;
const ll MAXN=151;
vector<pii>v,res;
ll n,m,flg,mx;
char mp[127],ch[MAXN][MAXN];
pii st[MAXN];
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
inline void swap()
{
	for(register int i=1;i<=mx;i++)
	{
		ch[i][i]=mp[ch[i][i]];
		for(register int j=i+1;j<=mx;j++)
		{
			swap(ch[i][j],ch[j][i]);
			ch[i][j]=mp[ch[i][j]],ch[j][i]=mp[ch[j][i]];
		}
	}
}
inline void flip(ll x,ll y)
{
	ll tp=0,typ=0;
	while((!typ&&ch[x][y]!=ch[x][y+1])||(typ&&ch[x][y]!=ch[x+1][y]))
	{
		st[++tp]=(pii){x,y},typ?x++:y++,typ^=1;
	}
	st[++tp]=(pii){x,y};
	while(tp)
	{
		tie(x,y)=st[tp--],typ^=1,v.push_back(flg?(pii){y,x}:(pii){x,y});
		typ?ch[x][y]=ch[x+1][y]='L',ch[x][y+1]=ch[x+1][y+1]='R':1;
		!typ?ch[x][y]=ch[x][y+1]='U',ch[x+1][y]=ch[x+1][y+1]='D':1;	
	}	
}
inline void calc()
{
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=m;j+=2)
		{
			ch[i][j]!='L'?flip(i,j):(void)1;
		}
	}
}
int main()
{
	n=read(),m=read(),flg=m&1,mx=max(n,m);
	mp['U']='L',mp['D']='R',mp['L']='U',mp['R']='D';
	for(register int i=1;i<=n;i++)
	{
		scanf("%s",ch[i]+1);
	}	
	flg?swap(),swap(n,m):(void)1,calc(),flg?swap(),swap(n,m):(void)1;
	res=v,v.clear(),memset(ch,0,sizeof(ch));
	for(register int i=1;i<=n;i++)
	{
		scanf("%s",ch[i]+1);
	}	
	flg?swap(),swap(n,m):(void)1,calc(),reverse(v.begin(),v.end());
	printf("%d\n",res.size()+v.size());
	for(auto i:res)
	{
		printf("%d %d\n",i.first,i.second);
	}
	for(auto i:v)
	{
		printf("%d %d\n",i.first,i.second);
	}
}