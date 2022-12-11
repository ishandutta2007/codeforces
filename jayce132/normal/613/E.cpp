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
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=2e3+20;
const int mod=1e9+7;

inline void pls(int &a,int b){ a+=b; if(a>=mod)a-=mod;}

int n,m;
char str[3][maxn];
char T[maxn];

int d[4][2]={{0,-1},{0,1},{-1,0},{1,0}};

inline void init()
{
	REP(i,1,2)scanf("%s",str[i]+1); n=strlen(str[1]+1);
	scanf("%s",T+1); m=strlen(T+1);

	if(m==1)
	{
		int ans=0;
		REP(i,1,2)REP(j,1,n)if(str[i][j]==T[1])ans++;
		printf("%d\n",ans);
		exit(0);
	}
	else if(m==2)
	{
		int ans=0;
		REP(x,1,2)REP(y,1,n)if(str[x][y]==T[1])
		{
			int xx,yy;
			REP(l,0,3)
			{
				xx=x+d[l][0]; yy=y+d[l][1];
				if(str[xx][yy]==T[2])ans++;
			}
		}
		printf("%d\n",ans);
		exit(0);
	}
	
}

int f[3][maxn][maxn];
int L[3][maxn][maxn],R[3][maxn][maxn];
int ans;

inline void doing(int op)
{
	memset(f,0,sizeof(f));
	memset(L,0,sizeof(L));
	memset(R,0,sizeof(R));
	REP(i,1,2)
	{
		REP(j,1,n)REP(k,1,m)
			if(str[i][j]==T[k])
				L[i][j][k]=L[i][j-1][k-1]+1;
			else L[i][j][k]=0;
		DREP(j,n,1)DREP(k,m,1)
			if(str[i][j]==T[k])
				R[i][j][k]=R[i][j+1][k-1]+1;
			else R[i][j][k]=0;
	}

	REP(j,1,n)
	{
		REP(i,1,2)
		{
			if(str[i][j]==T[1])pls(f[i][j][1],1);
			REP(k,1,min(j,m>>1))if(R[i][j-k+1][k]>=k && L[3-i][j][k<<1]>=k)
				pls(f[3-i][j][k<<1],1);
		}
		REP(i,1,2)
		{
			pls(ans,f[i][j][m]);
			REP(k,2,min(n-j,m>>1))if(R[3-i][j+1][m]>=k && L[i][j+k][m-k]>=k)
				pls(ans,f[i][j][m-(k<<1)]);
		}
		REP(i,1,2)REP(k,1,m)if(f[i][j][k])
		{
			if(str[i][j+1]==T[k+1])
			{
				pls(f[i][j+1][k+1],f[i][j][k]);
				if(str[3-i][j+1]==T[k+2])pls(f[3-i][j+1][k+2],f[i][j][k]);
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF613E.in","r",stdin);
	freopen("CF613E.out","w",stdout);
#endif
	init();
	doing(1);
	//cerr<<ans<<endl;
	REP(i,1,2)reverse(str[i]+1,str[i]+n+1);
	doing(2);
	printf("%d\n",ans);
	return 0;
}