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

const int maxn=1e3+20;

int n,m,a[maxn][maxn];

int A[maxn][maxn],B[maxn][maxn],AL[maxn],BL[maxn];

int tmp[maxn],top;


int main()
{
	n=read();m=read();
	REP(i,1,n)REP(j,1,m)a[i][j]=read();

	REP(i,1,n)
	{
		REP(j,1,m)tmp[j]=a[i][j];
		sort(tmp+1,tmp+m+1);
		AL[i]=unique(tmp+1,tmp+m+1)-(tmp+1);
		REP(j,1,m)A[i][j]=lower_bound(tmp+1,tmp+AL[i]+1,a[i][j])-tmp;
	}

	REP(j,1,m)
	{
		REP(i,1,n)tmp[i]=a[i][j];
		sort(tmp+1,tmp+n+1);
		BL[j]=unique(tmp+1,tmp+n+1)-(tmp+1);
		REP(i,1,n)B[i][j]=lower_bound(tmp+1,tmp+BL[j]+1,a[i][j])-tmp;
	}

	REP(i,1,n)
	{
		REP(j,1,m)
		{
			printf("%d ",max(A[i][j],B[i][j])+max(AL[i]-A[i][j],BL[j]-B[i][j]));
		}puts("");
	}
	
	return 0;
}