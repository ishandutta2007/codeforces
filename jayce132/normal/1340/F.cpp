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
inline int read()
{
    int s=0,f=1; char ch=getchar();
    while(!isdigit(ch) && ch!='-')ch=getchar();
    if(ch=='-')ch=getchar(),f=-1;
    while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
    return ~f?s:-s;
}

const int mod=1e9+7;

inline int power(int a,int b)
{
    int ans=1;
    while(b)
    {
	if(b&1)ans=(ll)ans*a%mod;
	b>>=1;
	a=(ll)a*a%mod;
    }
    return ans;
}

const int seed=181;
const int seedinv=power(seed,mod-2);
const int maxn=1e5+20;

const int M=320;

int a[maxn];
int id[maxn],p2[maxn];

struct BLK {
    int pa[M+20],phs[M+20],lp;
    int sa[M+20],shs[M+20],ls;
    int L,R,FAKE;

    inline void BUILD() {
	ls=lp=0; FAKE=0;
	REP(i,L,R)
	{
	    if(a[i]>0)
	    {
		sa[++ls]=a[i];
	    }else
	    {
		if(ls)
		{
		    if(sa[ls]!=-a[i])return FAKE=1,void();
		    else ls--;
		}else pa[++lp]=-a[i];
	    }
	}
	reverse(pa+1,pa+lp+1);
	REP(i,1,lp)phs[i]=((ll)phs[i-1]*seed+pa[i])%mod;
	REP(i,1,ls)shs[i]=((ll)shs[i-1]*seed+sa[i])%mod;
    }

    inline int SHash(int l,int r) {
	return (shs[r]-(ll)shs[l-1]*p2[r-l+1]%mod+mod)%mod;
    }

    inline int PHash(int l,int r) {
	return (phs[r]-(ll)phs[l-1]*p2[r-l+1]%mod+mod)%mod;
    }

};
BLK B[M+20];
int n,k;

inline void init()
{
    n=read();k=read();  
    REP(i,1,n)a[i]=read();
    REP(ID,1,(n-1)/M+1)
	B[ID].L=(ID-1)*M+1,B[ID].R=min(ID*M,n),B[ID].BUILD();
    REP(i,1,n)id[i]=(i-1)/M+1;
    p2[0]=1;
    REP(i,1,n)p2[i]=(ll)p2[i-1]*seed%mod;
}

struct node {
    int blk,r;
    node(int _blk=0,int _r=0){ blk=_blk; r=_r;}
};

bool query(int ql,int qr)
{
    vector<node>st;
    if(id[ql]==id[qr])
    {
	static int st[maxn],top;
	top=0;
	REP(i,ql,qr)
	    if(a[i]<0)
	    {
		if(top && st[top]==-a[i])top--;
		else return 0;
	    }else st[++top]=a[i];
	return top==0;
    }else
    {
	int idl=id[ql],idr=id[qr];
	REP(i,ql,B[idl].R)
	    if(a[i]<0)
	    {
		if(!st.empty() && a[st.back().r]==-a[i])st.pop_back();
		else return 0;
	    }else st.push_back(node(0,i));
	REP(i,idl+1,idr-1)
	{
	    if(B[i].FAKE)return 0;
	    int len=B[i].lp;
	    while(len>0 && !st.empty())
	    {
		node t=st.back(); st.pop_back();
		if(t.blk)
		{
		    int bj=min(t.r,len);
		    if(B[t.blk].SHash(t.r-bj+1,t.r)!=B[i].PHash(len-bj+1,len))
			return 0;
		    len-=bj;
		    t.r-=bj;
		    if(t.r>0)st.push_back(t);
		}else
		{
		    if(a[t.r]==B[i].pa[len])t.r--,len--;
		    else return 0;
		}
	    }
	    if(len)return 0;
	    if(B[i].ls)st.push_back(node(i,B[i].ls));
	}
	REP(i,B[idr].L,qr)
	    if(a[i]<0)
	    {
		if(!st.empty())
		{
		    node t=st.back(); st.pop_back();
		    if((t.blk?B[t.blk].sa[t.r]:a[t.r])!=-a[i])
			return 0;
		    t.r--;
		    if(t.blk && t.r>0)st.push_back(t);
		}else return 0;
	    }else st.push_back(node(0,i));
    }
    return st.empty();
}

inline void doing()
{
    int q=read();
    REP(i,1,q)
    {
	int op=read(),x=read(),y=read();
	if(op==1)a[x]=y,B[id[x]].BUILD();
	else {
	    if(query(x,y))puts("Yes");
	    else puts("No");
	}
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("637f.in","r",stdin);
    freopen("637f.out","w",stdout);
#endif
    init();
    doing();
    return 0;
}