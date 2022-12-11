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
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
inline void myassert(bool a,string s){ if(!a)cerr<<s<<endl,exit(0);}
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=520;
const int mod=1e9+7;

map<char,int>mp;

int ls[maxn],rs[maxn];
int tot,op[maxn];
//0~8:A,B,C,D,a,b,c,d,<-? 
//9~11:&,|,<-?

char str[maxn];
int n;

int to[maxn],RT;

int solve(int l,int r)
{
	int o=++tot;
	if(l==r)
	{
		if(str[l]=='?')op[o]=8;
		else op[o]=mp[str[l]];
		return o;
	}
	assert(to[l]);
	ls[o]=solve(l+1,to[l]-1);
	rs[o]=solve(to[l]+3,r-1);
	int MID=to[l]+1;
	if(str[MID]=='?')op[o]=11;
	else op[o]=mp[str[MID]];
	return o;
}

inline void init()
{
	REP(i,0,3)mp['A'+i]=i,mp['a'+i]=i+4;
	mp['&']=9; mp['|']=10;
	scanf("%s",str+1); n=strlen(str+1);
	vector<int>st;
	REP(i,1,n)
	{
		if(str[i]=='(')st.push_back(i);
		else if(str[i]==')')to[st.back()]=i,st.pop_back();
	}
	RT=solve(1,n);
}

int f[520][1<<16];

const int M=1<<16;

inline void pls(int &a,int b){ a+=b; a-=a>=mod?mod:0;}

inline void DFTand(int *p)
{
	for(int i=1;i<M;i<<=1)
		for(int j=0;j<M;j+=i<<1)
			for(int k=0;k<i;k++)
			{
				pls(p[j+k],p[i+j+k]);
			}
}

inline void DFTor(int *p)
{
	for(int i=1;i<M;i<<=1)
		for(int j=0;j<M;j+=i<<1)
			for(int k=0;k<i;k++)
			{
				pls(p[i+j+k],p[j+k]);
			}
}

inline void IDFTand(int *p)
{
	for(int i=1;i<M;i<<=1)
		for(int j=0;j<M;j+=i<<1)
			for(int k=0;k<i;k++)
			{
				pls(p[j+k],mod-p[i+j+k]);
			}
}

inline void IDFTor(int *p)
{
	for(int i=1;i<M;i<<=1)
		for(int j=0;j<M;j+=i<<1)
			for(int k=0;k<i;k++)
			{
				pls(p[i+j+k],mod-p[j+k]);
			}
}

void dfs(int u)
{
	if(!ls[u] && !rs[u])
	{
		REP(x,0,7)if(op[u]==x || op[u]==8)
		{
			int res=0;
			REP(j,0,15)
			{
				int t=0;
				if(x<=3)t=j>>x&1;
				else t=~j>>x-4&1;
				res|=t<<j;
			}
			f[u][res]++;
		}
		return;
	}
	dfs(ls[u]); dfs(rs[u]);
	int L=ls[u],R=rs[u];
	static int A[1<<16],B[1<<16];

	if(op[u]==9 || op[u]==11)
	{
		memcpy(A,f[L],sizeof(A));
		memcpy(B,f[R],sizeof(B));
		DFTand(A); DFTand(B);
		REP(i,0,(1<<16)-1)A[i]=(ll)A[i]*B[i]%mod;
		IDFTand(A);
		memcpy(f[u],A,sizeof(A));
	}

	if(op[u]==10 || op[u]==11)
	{
		memcpy(A,f[L],sizeof(A));
		memcpy(B,f[R],sizeof(B));
		DFTor(A); DFTor(B);
		REP(i,0,(1<<16)-1)A[i]=(ll)A[i]*B[i]%mod;
		IDFTor(A);
		REP(i,0,(1<<16)-1)f[u][i]=(f[u][i]+A[i])%mod;
	}
}

inline void doing()
{
	dfs(RT);
	int m=read();

	static int a[maxn],b[maxn];

	REP(th,1,m)
	{
		REP(i,0,3)a[th]|=read()<<i;
		b[th]=read();
	}
	int ans=0;
	REP(i,0,(1<<16)-1)
	{
		int flg=0;
		REP(j,1,m)if((i>>a[j]&1)==b[j]);
		else { flg=1;break;}
		if(!flg)pls(ans,f[RT][i]);
	}
	printf("%d\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}