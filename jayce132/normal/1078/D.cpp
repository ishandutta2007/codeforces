#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cassert>
#include<vector>
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

const int maxn=3e5+20;
const int maxp=19;

int n,r[maxn];
int L[20][maxn],R[20][maxn];

int stmn[20][maxn],stmx[20][maxn];
int lg[maxn];

inline void init()
{
	n=read();
	REP(i,1,n)r[i]=read(),r[i+n]=r[i+n+n]=r[i];
	REP(i,1,3*n)L[0][i]=max(i-r[i],1),R[0][i]=min(i+r[i],3*n);
	REP(i,2,3*n)lg[i]=lg[i>>1]+1;
}

inline int querymx(int l,int r)
{
	int k=lg[r-l+1];
	return max(stmx[k][l],stmx[k][r-(1<<k)+1]);
}

inline int querymn(int l,int r)
{
	int k=lg[r-l+1];
	return min(stmn[k][l],stmn[k][r-(1<<k)+1]);
}

int le[maxn],ri[maxn],ans[maxn];

inline void doing()
{
	REP(j,1,18)
	{
		REP(i,1,3*n)stmn[0][i]=L[j-1][i],stmx[0][i]=R[j-1][i];
		REP(jj,1,18)REP(i,1,3*n-(1<<jj)+1)stmn[jj][i]=min(stmn[jj-1][i],stmn[jj-1][i+(1<<jj-1)]);
		REP(jj,1,18)REP(i,1,3*n-(1<<jj)+1)stmx[jj][i]=max(stmx[jj-1][i],stmx[jj-1][i+(1<<jj-1)]);
		REP(i,1,3*n)L[j][i]=max(querymn(L[j-1][i],R[j-1][i]),1);
		REP(i,1,3*n)R[j][i]=min(querymx(L[j-1][i],R[j-1][i]),3*n);
	}

	REP(i,1,n)le[i]=ri[i]=i+n;
	DREP(j,18,0)
	{
		REP(i,1,3*n)stmn[0][i]=L[j][i],stmx[0][i]=R[j][i];
		REP(jj,1,18)REP(i,1,3*n-(1<<jj)+1)stmn[jj][i]=min(stmn[jj-1][i],stmn[jj-1][i+(1<<jj-1)]);
		REP(jj,1,18)REP(i,1,3*n-(1<<jj)+1)stmx[jj][i]=max(stmx[jj-1][i],stmx[jj-1][i+(1<<jj-1)]);
		REP(i,1,n)
		{
			int LL=querymn(le[i],ri[i]),RR=querymx(le[i],ri[i]);
			if(RR-LL<n-1)le[i]=LL,ri[i]=RR,ans[i]+=1<<j;
		}
	}
	REP(i,1,n)if(le[i]-ri[i]<n-1)ans[i]++;
	REP(i,1,n)printf("%d ",ans[i]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}