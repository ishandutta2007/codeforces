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
	int s=0,f=1; char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=1e3+20;

int n;

#define pii pair<int,int>
vector<pii >ed;

inline void init()
{
	n=read();
	REP(i,1,n-1)
	{
		int x=read(),y=read();
		ed.push_back(mkr(x,y));
	}
}

inline int ask(int a,int b)
{
	printf("? %d %d\n",a,b);cout<<endl;
	int x=read();
	return x;
}

inline void Out(int x)
{
	printf("! %d\n",x);cout<<endl;exit(0);
}

void solve(vector<pii>ed)
{
	if(SZ(ed)==1)
	{
		int t=ask(ed.front().fi,ed.front().se);
		Out(t);exit(0);
	}
	static int rd[maxn];
	memset(rd,0,sizeof(rd));
	for(pii x:ed)rd[x.fi]++,rd[x.se]++;
	int a=0,b=0;
	REP(i,1,n)if(rd[i]==1)
	{
		if(!a)a=i;
		else b=i;
	}
		
	if(SZ(ed)==2)
	{
		int t=ask(a,b);
		Out(t);exit(0);
	}
	int t=ask(a,b);
	if(t==a || t==b)Out(t),exit(0);
	vector<pii>::iterator it,A,B;
	
	for(it=ed.begin();it!=ed.end();it++)
	{
		if(it->fi==a || it->se==a)A=it;
	}
	ed.erase(A); 
	for(it=ed.begin();it!=ed.end();it++)
	{
		if(it->fi==b || it->se==b)B=it;
	}
	ed.erase(B);
	solve(ed);
}

inline void doing()
{
	solve(ed);
}

int main()
{
	init();doing();
	return 0;
}