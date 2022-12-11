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

const int maxn=1e3+20;
const int mod=1e9+7;

struct node {
	int ch[10],fail,goal;
};
node t[maxn*25];
int ttot;

int n,m,d;
char str[1020];
char A[52],B[52];

inline void insert(char *s,int len)
{
	int u=1;
	REP(j,1,len)
	{
		int &v=t[u].ch[s[j]];
		if(!v)v=++ttot;
		u=v;
	}
	t[u].goal=1;
}

inline void get_fail()
{
	REP(j,0,9)t[0].ch[j]=1;
	queue<int>q;
	q.push(1);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		REP(i,0,9)
		{
			int &v=t[u].ch[i];
			if(!v)v=t[t[u].fail].ch[i];
			else t[v].fail=t[t[u].fail].ch[i],q.push(v);
		}
	}
}

inline void init()
{
	scanf("%s",str+1); n=strlen(str+1);
	REP(i,1,n)str[i]-='0';
	scanf("%s\n%s\n",A+1,B+1);
	m=strlen(A+1);d=m/2; 
	REP(i,1,m)A[i]-='0',B[i]-='0';
	int t=m;
	while(A[t]==0)A[t--]=9;A[t]--;
	ttot=1;
	REP(i,1,n-d+1)insert(str+i-1,d);
	get_fail();
}

int dp[52][maxn*25][2][2];
inline void pls(int &a,int b){ a+=b; a-=a>=mod?mod:0;}

inline int solve(char *A)
{
	memset(dp,0,sizeof(dp));
	dp[0][1][0][1]=1;
	REP(i,1,m)REP(u,1,ttot)REP(gans,0,1)REP(op,0,1)if(dp[i-1][u][gans][op])
	{
		REP(k,0,op?A[i]:9)
		{
			int v=t[u].ch[k];
			pls(dp[i][v][gans|t[v].goal][op&(k==A[i])],dp[i-1][u][gans][op]);
		}
	}
	int ans=0;
	REP(j,1,ttot)REP(op,0,1)pls(ans,dp[m][j][1][op]);
	return ans;
}

inline void doing()
{
	int t=(solve(B)-solve(A)+mod)%mod;	
	printf("%d\n",t);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF585F.in","r",stdin);
	freopen("CF585F.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}