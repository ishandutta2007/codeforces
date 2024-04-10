#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,MOD=998244353,INVP=828542813;
struct Matrix{
	ll num[2][2];
	Matrix()
	{
		memset(num,0,sizeof(num));
	}
	inline ll* operator [](const ll &x)
	{
		return num[x];
	}
	inline const ll* operator [](const ll &x)const
	{
		return num[x];
	}
};
struct SegmentTree{
	ll l,r;
	Matrix val;
};
struct Query{
	ll d,v,id,dl,dr;
	inline bool operator <(const Query &rhs)const
	{
		return (li)d*rhs.v<(li)v*rhs.d;
	}
};
SegmentTree tree[MAXN<<2];
Matrix mat[MAXN];
Query qry[MAXN<<2];
Matrix id,m1,m2,r;
ll n,pr,qcnt,res,r2;
ll x[MAXN],v[MAXN];
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
inline ll qpow(ll base,ll exponent)
{
	ll res=1;
	while(exponent)
	{
		if(exponent&1)
		{
			res=(li)res*base%MOD;
		}
		base=(li)base*base%MOD,exponent>>=1;
	}
	return res;
}
inline Matrix operator *(Matrix x,Matrix y)
{
	Matrix res;
	res[0][0]=((li)x[0][0]*y[0][0]+(li)x[0][1]*y[1][0])%MOD;
	res[0][1]=((li)x[0][0]*y[0][1]+(li)x[0][1]*y[1][1])%MOD;
	res[1][0]=((li)x[1][0]*y[0][0]+(li)x[1][1]*y[1][0])%MOD;
	res[1][1]=((li)x[1][0]*y[0][1]+(li)x[1][1]*y[1][1])%MOD;
	return res;
}
#define ls node<<1
#define rs (node<<1)|1
inline void update(ll node)
{
	tree[node].val=tree[ls].val*tree[rs].val;
}
inline void create(ll l,ll r,ll node)
{
	tree[node]=(SegmentTree){l,r};
	if(l==r)
	{
		return (void)(tree[node].val=mat[l]);
	}
	ll mid=(l+r)>>1;
	create(l,mid,ls),create(mid+1,r,rs),update(node);
}
inline void change(ll pos,ll x,ll node)
{
	if(tree[node].l==tree[node].r)
	{
		return (void)(tree[node].val=mat[x]);
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	change(pos,x,pos<=mid?ls:rs),update(node); 
}
int main()
{
	n=read(),id[0][0]=id[1][1]=1;
	for(register int i=1;i<=n;i++)
	{
		x[i]=read(),v[i]=read(),pr=(li)read()*INVP%MOD;
		mat[i][0][1]=mat[i][1][1]=pr,mat[i][0][0]=mat[i][1][0]=(MOD+1-pr)%MOD;
	}
	for(register int i=2;i<=n;i++)
	{
		qry[++qcnt]=(Query){x[i]-x[i-1],v[i]+v[i-1],i,1,0};
		v[i]>v[i-1]?qry[++qcnt]=(Query){x[i]-x[i-1],v[i]-v[i-1],i,0,0},1:1;
		v[i]<v[i-1]?qry[++qcnt]=(Query){x[i]-x[i-1],v[i-1]-v[i],i,1,1},1:1;
	}
	sort(qry+1,qry+qcnt+1),create(1,n,1);
	for(register int i=1;i<=qcnt;i++)
	{
		m1=mat[qry[i].id],m2=Matrix(),r2=(li)qry[i].d*qpow(qry[i].v,MOD-2)%MOD;
		m2[qry[i].dl][qry[i].dr]=m1[qry[i].dl][qry[i].dr];
		mat[qry[i].id]=m2,change(qry[i].id,qry[i].id,1);
		r=tree[1].val,res=(res+(li)r2*(r[0][0]+r[0][1])%MOD)%MOD;
		m1[qry[i].dl][qry[i].dr]=0,mat[qry[i].id]=m1;
		change(qry[i].id,qry[i].id,1);
	}
	printf("%d\n",res);
}