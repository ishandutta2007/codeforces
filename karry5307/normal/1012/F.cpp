#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=5e6+51;
struct Item{
	ll l,r,t,x;
	inline bool operator <(const Item &rhs)const
	{
		return l<rhs.l;
	}
	inline bool operator >(const Item &rhs)const
	{
		return t<rhs.t;
	}
};
Item it[2][5051];
ll n,p,pt,ptt;
ll res[5051][2],prv[MAXN],f[MAXN],s[2];
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
inline void calc(ll x,ll tp)
{
	ll nxt,nx;
	if(f[x]==0x3f3f3f3f)
	{
		return;
	}
	while(x)
	{
		res[nx=it[1][nxt=prv[x]].x][0]=tp;
		res[nx][1]=f[x]-it[1][nxt].t,x^=(1<<(nx-1));
	}
}
int main()
{
	n=read(),p=read(),f[0]=1;
	for(register int i=1;i<=n;i++)
	{
		it[0][i].l=read(),it[0][i].r=it[0][i].l+read()-1;
		it[0][i].t=read(),it[0][i].x=i,it[1][i]=it[0][i];
	}
	sort(it[0]+1,it[0]+n+1),sort(it[1]+1,it[1]+n+1,greater<Item>());
	for(register int i=1;i<(1<<n);i++)
	{
		f[i]=0x3f3f3f3f;
	}
	for(register int i=0;i<(1<<n);i++)
	{
		if(f[i]==0x3f3f3f3f)
		{
			continue;
		}
		pt=f[i],s[0]=s[1]=1;
		for(register int j=1;j<=n;j++)
		{
			if(i&(1<<(it[1][j].x-1)))
			{
				continue;
			}
			while(1)
			{
				while(s[0]<=n&&it[0][s[0]].r<pt)
				{
					s[0]++;
				}
				while(s[1]<=n&&(it[0][s[1]].l<pt||!(i&(1<<(it[0][s[1]].x-1)))))
				{
					s[1]++;
				}
				if(s[0]<=n&&it[0][s[0]].l<=pt)
				{
					pt=it[0][s[0]].r+1;
					continue;
				}
				if(s[1]<=n&&pt+it[1][j].t>=it[0][s[1]].l)
				{
					pt=it[0][s[1]].r+1;
					continue;
				}
				break;
			}
			if(pt+it[1][j].t<it[1][j].l)
			{
				ptt=i|(1<<(it[1][j].x-1));
				if(f[ptt]>pt+it[1][j].t)
				{
					f[ptt]=pt+it[1][j].t,prv[ptt]=j;
				}
			}
		}
	}
	if(p==1)
	{
		calc((1<<n)-1,1);
	}
	else
	{
		for(register int i=0;i<(1<<n);i++)
		{
			if(f[i]!=0x3f3f3f3f&&f[(1<<n)-1-i]!=0x3f3f3f3f)
			{
				calc(i,1),calc((1<<n)-1-i,2);
				break;
			}
		}
	}
	if(!res[1][0])
	{
		return puts("NO"),0;
	}
	puts("YES");
	for(register int i=1;i<=n;i++)
	{
		printf("%d %d\n",res[i][0],res[i][1]);
	}
}