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

int k,n;
struct point {
	int x,y;
	point(int _x=0,int _y=0){ x=_x; y=_y;}
};
point stone[maxn],monster[maxn];

inline point operator -(point a,point b){ return point(a.x-b.x,a.y-b.y);}
inline ll operator *(point a,point b){ return 1ll*a.x*b.x+1ll*a.y*b.y;}
inline ll cross(point a,point b){ return 1ll*b.x*a.y-1ll*a.x*b.y;}

vector<int> f[10][maxn];

inline void init()
{
	k=read();n=read();
	REP(i,1,k)
	{
		int x=read(),y=read();
		stone[i]=point(x,y);
	}
	REP(i,1,n)
	{
		int x=read(),y=read();
		monster[i]=point(x,y);
	}
	REP(i,1,k)REP(j,1,n)
	{
		REP(k,1,n)if(k!=j)
		{
			if(cross(monster[j]-stone[i],monster[k]-stone[i])==0 && (stone[i]-monster[k])*(monster[j]-monster[k])<0)
				f[i][j].push_back(k);
		}
	}
}

int vis[maxn];

bool solve(int S,vector<int> a)
{
	if(SZ(a)==0)return 1;
	REP(th,0,0)
	{
		int g=a[th];
		vis[g]=1;
		int num=__builtin_popcount(S)-1;
		vector<int>na;
		REP(i,1,k)if(S>>i-1&1)
		{
			if(SZ(f[i][g])<=num)
			{
				na.clear();
				for(int x:a)if(!vis[x])na.push_back(x);
				for(int x:f[i][g])if(!vis[x])na.push_back(x);
				sort(na.begin(),na.end()); int len=unique(na.begin(),na.end())-na.begin();
				na.resize(len);
				if(len>num)continue;
				bool flg=solve(S&~(1<<i-1),na);
				if(flg)return 1;
			}
		}
		vis[g]=0;
	}
	return 0;
}

inline void doing()
{
	int ans=0;
	REP(i,1,n)
	{
		memset(vis,0,sizeof(int)*(n+1));
		int tmp=solve((1<<k)-1,{i});
		ans+=tmp;
		//cerr<<monster[i].x<<" "<<monster[i].y<<" "<<tmp<<" "<<endl;
	}
	printf("%d\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("cf698d.in","r",stdin);
	freopen("cf698d.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}