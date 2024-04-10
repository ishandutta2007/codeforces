#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e3+51;
vector<ll>v;
ll n,m,kk,totd,r1,r2,x,pos,pivot,flg;
ll r[MAXN][2],val[MAXN],res[MAXN];
char op[10],ch[10],mp[128];
bitset<MAXN>bs[MAXN];
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
	n=read(),m=read(),mp['R']=1,mp['Y']=2,mp['B']=3;
	for(register int i=1;i<=n;i++)
	{
		r[i][0]=2,r[i][1]=1;
	}
	for(register int i=1;i<=m;i++)
	{
		scanf("%s",op+1),v.clear(),kk=read();
		for(register int j=1;j<=kk;j++)
		{
			v.push_back(read());
		}
		if(op[1]=='m')
		{
			scanf("%s",ch+1),x=mp[ch[1]],r1=(++totd),r2=(++totd);
			for(register int j:v)
			{
				pos=2*j-1,val[r1]=(x>>1)&1,val[r2]=x&1;
				(r[j][0]&2)?bs[r1][pos]=1:1,(r[j][0]&1)?bs[r1][pos+1]=1:1;
				(r[j][1]&2)?bs[r2][pos]=1:1,(r[j][1]&1)?bs[r2][pos+1]=1:1;
			}
		}
		if(op[1]=='R'&&op[2]=='Y')
		{
			for(register int j:v)
			{
				swap(r[j][0],r[j][1]);
			}
		}
		if(op[1]=='R'&&op[2]=='B')
		{
			for(register int j:v)
			{
				r[j][0]^=r[j][1];
			}
		}
		if(op[1]=='Y'&&op[2]=='B')
		{
			for(register int j:v)
			{
				r[j][1]^=r[j][0];
			}
		}
	}
	pos=1;
	for(register int i=1;i<=2*n;i++)
	{
		pivot=1e9;
		for(register int j=pos;j<=totd;j++)
		{
			if(bs[j][i])
			{
				pivot=j;
				break;
			}
		}
		if(pivot==1e9)
		{
			continue;
		}
		swap(bs[pos],bs[pivot]),swap(val[pos],val[pivot]);
		for(register int j=1;j<=totd;j++)
		{
			j!=pos&&bs[j][i]?bs[j]^=bs[pos],val[j]^=val[pos]:1;
		}
		pos++;
	}
	for(register int i=1;i<=totd;i++)
	{
		if(!bs[i].count()&&val[i])
		{
			return puts("NO"),0;
		}
	}
	puts("YES");
	for(register int i=totd;i>=1;i--)
	{
		flg=0;
		for(register int j=bs[i]._Find_first();j<=2*n;j=bs[i]._Find_next(j))
		{
			!flg?flg=1,val[i]?res[j]=1:1:1;
			for(register int k=i-1;k;k--)
			{
				bs[k][j]?bs[k][j]=0,val[k]^=res[j]:1;
			}
		}
	}
	for(register int i=1;i<=n;i++)
	{
		x=(res[2*i-1]<<1)|res[2*i],putchar(".RYB"[x]);
	}
}