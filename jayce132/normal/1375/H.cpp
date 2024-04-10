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

#define merge MErge

const int maxn=1e5+20;
const int M=256;

int n,q;
int a[maxn],id[maxn];
int tot;
int x[maxn*22],y[maxn*22];

int merge(int a,int b)
{
    if(!a || !b)return a|b;
    ++tot;
    x[tot]=a; y[tot]=b;
    return tot;
}

void solve(int L,int R,vector<int>st,vector<vector<int> >&f)
{
    if(L==R)return f={{st.back()}},void(); 
    int MID=L+R>>1,len=SZ(st);
    vector<int>Left,Right;
    for(int x:st)
	if(a[x]<=MID)Left.push_back(x);
	else Right.push_back(x);
    vector<vector<int> >Lf,Rf;
    solve(L,MID,Left,Lf);
    solve(MID+1,R,Right,Rf);
    f.resize(len); REP(i,0,len-1)f[i].resize(len);
    int l1=0,l2=0,r1=-1,r2=-1,len1=MID-L+1,len2=R-MID;
    REP(i,0,len-1)
    {
	r1=-1; r2=-1;
	REP(j,i,len-1)
	{
	    while(l1<len1 && Left[l1]<st[i])++l1;
	    while(l2<len2 && Right[l2]<st[i])++l2;
	    while(r1<len1-1 && Left[r1+1]<=st[j])++r1;
	    while(r2<len2-1 && Right[r2+1]<=st[j])++r2;
	    if(l1>r1)f[i][j]=Rf[l2][r2];
	    else if(l2>r2)f[i][j]=Lf[l1][r1];
	    else f[i][j]=merge(Lf[l1][r1],Rf[l2][r2]);
	}
    }
}

struct BLOCK {
    int L,R,len;

    vector<int>st;
    
    vector<vector<int> > f;

    inline void Init() {
	REP(i,L,R)st.push_back(id[i]);
	sort(st.begin(),st.end());
	solve(L,R,st,f);
    }
    
};
BLOCK B[40];
int blknum;

inline void init()
{
    n=read();q=read();
    REP(i,1,n)a[i]=read(),id[a[i]]=i;
    tot=n;
    REP(i,1,blknum=(n-1)/M+1)
    {
	B[i].L=(i-1)*M+1; B[i].R=min(i*M,n); B[i].len=B[i].R-B[i].L+1;
	B[i].Init();
    }
}

int ans[maxn];

inline void doing()
{
    REP(i,1,q)
    {
	int l=read(),r=read();
	int p=0;
	REP(j,1,blknum)
	{
	    vector<int> &st=B[j].st;
	    int l1=lower_bound(st.begin(),st.end(),l)-st.begin(),r1=upper_bound(st.begin(),st.end(),r)-st.begin()-1;
	    if(l1<=r1)p=merge(p,B[j].f[l1][r1]);
	}
	ans[i]=p;
    }
    printf("%d\n",tot);
    REP(i,n+1,tot)printf("%d %d\n",x[i],y[i]);
    REP(i,1,q)printf("%d ",ans[i]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("h.in","r",stdin);
    freopen("h.out","w",stdout);
#endif
    init();
    doing();
    return 0;
}