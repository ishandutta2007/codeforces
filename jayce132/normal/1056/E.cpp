#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=1e6+20;
const int inf=0x3f3f3f3f;

char S[maxn];
int n0,n1,n,m;
char T[maxn];

int tag[maxn],v[maxn],x[maxn],y[maxn],sa[maxn],rk[maxn],ht[maxn];
int st[maxn][20],lg[maxn];

inline void get_sa(int n)
{
	int m=26;
	REP(i,1,n)tag[x[i]=T[i]-'a'+1]++;
	REP(i,1,m)tag[i]+=tag[i-1];
	DREP(i,n,1)sa[tag[x[i]]--]=i;
	for(int j=1,p=0;p<n;m=p,j<<=1)
	{
		p=0;
		REP(i,n-j+1,n)y[++p]=i;
		REP(i,1,n)if(sa[i]>j)y[++p]=sa[i]-j;
		REP(i,1,m)tag[i]=0;
		REP(i,1,n)tag[v[i]=x[y[i]]]++;
		REP(i,1,m)tag[i]+=tag[i-1];
		DREP(i,n,1)sa[tag[v[i]]--]=y[i];
		REP(i,1,n)v[i]=x[i];
		p=1; x[sa[1]]=1;
		REP(i,2,n)x[sa[i]]=v[sa[i]]==v[sa[i-1]] && v[sa[i]+j]==v[sa[i-1]+j] ? p: ++p;
	}
	REP(i,1,n)rk[sa[i]]=i;

	int j=0;
	REP(i,1,n)
	{
		if(rk[i]==n)continue;
		if(j)j--;
		while(i+j<=n && sa[rk[i]+1]+j<=n && T[i+j]==T[sa[rk[i]+1]+j])++j;
		ht[rk[i]]=j;
	}
	REP(i,1,n-1)st[i][0]=ht[i];
	for(int j=1;(1<<j)<n;j++)
		REP(i,1,(n-(1<<j)))st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
	REP(i,2,n-1)lg[i]=lg[i>>1]+1;
}

inline int query(int l,int r)
{
	if(l==r)return inf;
	int L=rk[l],R=rk[r];
	if(L>R)swap(L,R);
	R--;
	int k=lg[R-L+1];
	return min(st[L][k],st[R-(1<<k)+1][k]);
}


inline void debug()
{
	cerr<<query(1,3)<<endl;
}

inline void init()
{
	scanf("%s",S+1);n=strlen(S+1);
	scanf("%s",T+1);m=strlen(T+1);
	REP(i,1,n)if(S[i]=='0')n0++;
	else n1++;
	get_sa(m);
	//debug();
}

inline void doing()
{
	int ans=0;
	REP(x,1,m/n0)
		if(!((m-x*n0)%n1))
	{
		int y=(m-x*n0)/n1;
		if(!y)continue;
		int now=1,l0=-1,l1=-1,flg=0;
		REP(i,1,n)
		{
			if(S[i]=='0')
			{
				if(l0==-1)l0=now;
				else if(query(now,l0)<x){ flg=1; break;}
				now+=x;
			}else
			{
				if(l1==-1)l1=now;
				else if(query(now,l1)<y){ flg=1; break;}
				now+=y;
			}
		}
		ans+=!flg && (x!=y || query(l0,l1)<x );
	}
	printf("%d\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}