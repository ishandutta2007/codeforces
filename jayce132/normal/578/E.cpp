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

const int maxn=1e5+20;

char str[maxn];
int n;

inline void init()
{
	scanf("%s",str+1); n=strlen(str+1);
}

list<int>walk[maxn];
int tot;
vector<int>L,R;

inline void add(int x,int y)
{
	walk[x].splice(walk[x].end(),walk[y]);
}

inline void doing()
{
	REP(i,1,n)
		if(str[i]=='L')
		{
			int t=0;
			if(SZ(R)>0)t=R.back(),R.pop_back();
			else t=++tot;
			walk[t].push_back(i);
			L.push_back(t);
		}else
		{
			int t=0;
			if(SZ(L)>0)t=L.back(),L.pop_back();
			else t=++tot;
			walk[t].push_back(i);
			R.push_back(t);
		}
	/*REP(i,1,tot)
	{
		for(int x:walk[i])cerr<<x<<" ";cerr<<endl;
		}*/
	vector<int>LL,RR,LR,RL;
	for(int x:L)
		if(str[walk[x].front()]=='L')LL.push_back(x);
		else RL.push_back(x);
	for(int x:R)
		if(str[walk[x].front()]=='L')LR.push_back(x);
		else RR.push_back(x);
	while(SZ(LL)>=1 && SZ(RR)>=1)
	{
		int x=LL.back(),y=RR.back();
		add(x,y); LL.pop_back(); RR.pop_back();
		LR.push_back(x);
	}
	while(SZ(LR)>1)add(LR.front(),LR.back()),LR.pop_back();
	while(SZ(RL)>1)add(RL.front(),RL.back()),RL.pop_back();
	if(SZ(LR)>=1 && SZ(RL)>=1)
	{
		int x=LR.front(),y=RL.front();
		int u=walk[x].back(),v=walk[y].back();
		if(u>v)walk[x].pop_back(),walk[y].push_back(u),add(x,y),RL.pop_back();
		else walk[x].push_back(v),walk[y].pop_back(),add(x,y),RL.pop_back();
	}
	int x=0,y=0,opx,opy,ans=0;
	if(SZ(LL)>=1)x=LL.front(),opx=0;
	if(SZ(RR)>=1)x=RR.front(),opx=1;
	if(SZ(LR)>=1)y=LR.front(),opy=0;
	if(SZ(RL)>=1)y=RL.front(),opy=1;
	
	if(!x || !y)ans=x|y;
	else {
		if(opx==0 && opy==1)add(x,y),ans=x;
		else if(opx==1 && opy==0)add(x,y),ans=x;
		else 
		{
			int u=walk[x].back(),v=walk[y].back();
			if(u>v)walk[x].pop_back(),walk[y].push_back(u),add(x,y);
			else walk[x].push_back(v),walk[y].pop_back(),add(x,y);
			ans=x;
		}
	}
	printf("%d\n",tot-1);
	for(int x:walk[ans])printf("%d ",x);puts("");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("587e.in","r",stdin);
	freopen("587e.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}