#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline void myassert(bool a,string s)
{
    if(!a)cerr<<s<<endl,exit(0);
}
inline int read()
{
    int s=0,f=1; char ch=getchar();
    while(!isdigit(ch) && ch!='-')ch=getchar();
    if(ch=='-')ch=getchar(),f=-1;
    while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
    return ~f?s:-s;
}

const int maxn=3e5+20;

int n;
ll t[maxn];
int c[maxn];

inline void init()
{
    n=read();
    REP(i,1,n)scanf("%lld",t+i);
    reverse(t+1,t+n+1);
    int flg=1;
    REP(i,1,n)flg&=t[i]<=1;
    if(flg)
    {
	REP(i,1,n)printf("%d",0);
	exit(0);
    }
}

#define pii pair<int,int>

inline ll check(ll l,ll r,ll s)
{
    if(s<0)return -1;
    if(!s)return 0;
    if(l>r)return -1;
    ll L=0,R=r-l+1;
    while(L<R)
    {
	ll mid=L+R+1>>1;
	if((l+l+mid-1)*mid<=s*2)L=mid;
	else R=mid-1;
    }
    return (r+r-L+1)*L>=s*2?L:-1;
}

inline void Set(ll l,ll r,ll s)
{
    ll num=check(l,r,s);
    if(num==-1)myassert(0,"Set 1 gg");
    while(num)
    {
	num--;
	if(num==0)c[s]=1;
	else {
	    ll L=(l+l+num-1)*num>>1,R=(r+r-num+1)*num>>1;
	    if(s-r>=L)c[r]=1,s-=r,r--;
	    else if(s-l<=R)c[l]=1,s-=l,l++;
	    else myassert(0,"Set 2 gg");
	}
    }
}

struct node {
    bool ext;
    ll pos,val;
    node(){ }
    node(ll a,ll b){ ext=1; pos=a; val=b;}
};

node f[maxn][2];

inline void doing()
{
    static pii st[maxn]; int top=0;
    DREP(i,n,1)if(t[i])
    {
	if(top && t[st[top].se]>=t[i])
	    st[top].fi=i;
	else st[++top]=mkr(i,i);
    }
    reverse(st+1,st+top+1);
    st[1].fi=1;
    st[top+1]=mkr(n+1,n+1);
    f[top+1][0]=node(n+1,0);

    st[0]=mkr(0,0);
    
    DREP(i,top,1)
    {
	int l=st[i].fi,r=st[i].se;
	if(st[i].fi>1)
	{
	    if(l<r)
	    {
		if(t[l]==t[r])
		{
		    DREP(j,l-1,st[i-1].se+1)
		    {
			int flg=1;
			REP(op,0,1)if(f[i+1][op].ext)
			{
			    node p=f[i+1][op]; ll nv=t[l]-1;
			    if(~check(r+1,p.pos-1,nv-j-p.val))
			    {
				f[i][0]=node(j,nv);
				flg=0;
			    }
			}
			if(!flg)break;
		    }
		}else
		{
		    REP(op,0,1)if(f[i+1][op].ext)
		    {
			node p=f[i+1][op]; ll nv=t[l];
			if(~check(r+1,p.pos-1,nv-l-p.val))
			{
			    f[i][0]=node(l,nv);
			}
		    }
		}
	    }else
	    {
		DREP(j,l-1,st[i-1].se+1)
		{
		    int flg=1;
		    REP(op,0,1)if(f[i+1][op].ext)
		    {
			node p=f[i+1][op]; ll nv=t[l]-1;
			if(~check(r+1,p.pos-1,nv-j-p.val))
			{
			    f[i][0]=node(j,nv);
			    flg=0;
			}
		    }
		    if(!flg)break;
		}

		REP(op,0,1)if(f[i+1][op].ext)
		{
		    node p=f[i+1][op]; ll nv=t[l];
		    if(~check(r+1,p.pos-1,nv-l-p.val))
		    {
			f[i][1]=node(l,nv);
		    }
		}
	    }
	}else
	{
	    ll mn=1ll<<60,mx=0;
	    int id=0;
	    REP(j,l,r)if(t[j])chkmin(mn,t[j]),chkmax(mx,t[j]);
	    if(l==r)mx=mn+1;
	    if(mn<mx)REP(j,l,r)if(t[j]==mn){ id=j;break;}
	    REP(j,0,r)if((id==0 && !t[j]) || id==j)
	    {
		REP(op,0,1)if(f[i+1][op].ext)
		{
		    node p=f[i+1][op]; ll nv=mx-1;
		    if(~check(r+1,p.pos-1,nv-j-p.val))
		    {
			f[i][0]=node(j,nv);
		    }
		}
	    }
	}
    }
    ll pos,val;
    REP(op,0,1)if(f[1][op].ext)
	pos=f[1][op].pos,val=f[1][op].val;
    REP(i,1,top)
    {
	int l=st[i].fi,r=st[i].se;
	c[pos]=1;
	int flg=0;
	REP(op,0,1)if(f[i+1][op].ext)
	{
	    node p=f[i+1][op];
	    if(~check(r+1,p.pos-1,val-p.val-pos))
	    {
		Set(r+1,p.pos-1,val-p.val-pos);
		pos=p.pos; val=p.val;
		flg=1;
		break;
	    }
	}
	if(!flg)myassert(0,"wrong while constructing ");
    }
    DREP(i,n,1)printf("%d",c[i]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("cf1349e.in","r",stdin);
    freopen("cf1349e.out","w",stdout);
#endif
    init();
    doing();
    return 0;
}