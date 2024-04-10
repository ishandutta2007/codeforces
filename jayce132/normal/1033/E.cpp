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
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=620;

int n;

inline int query(vector<int> v)
{
	if(v.size()==1)return 0;
	printf("? %d\n",(int)v.size());
	for(int t:v)printf("%d ",t); puts("");
	fflush(stdout);
	return read();
}

inline int twosets(vector<int> u,vector<int> v,int A=-1,int B=-1)
{
	vector<int>tmp;
	for(int t:u)tmp.push_back(t); for(int t:v)tmp.push_back(t);
	return query(tmp)-(~A?A:query(u))-(~B?B:query(v));
}

inline void init()
{
	fflush(stdout); n=read();
	if(n==1)printf("Y 1\n1"),exit(0);
}

vector<int>now;
int vis[maxn];

struct node {
	int v,next;
};
node e[maxn<<1];
int cnt,start[maxn];
inline void addedge(int u,int v){ e[++cnt]=(node){v,start[u]};start[u]=cnt;}

int dis[maxn];
vector<int> odd,even;

void dfs(int u,int fa)
{
	if(dis[u])odd.push_back(u); else even.push_back(u);
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dis[v]=dis[u]^1;
		dfs(v,u);
	}
}

vector<int>circle;
int goal;

void dfs1(int u,int fa)
{
	circle.push_back(u);
	if(u==goal)
	{
		printf("%d\n",(int)circle.size());
		for(int t:circle)printf("%d ",t); puts("");
		exit(0);
	}
	EREP(i,u)if(e[i].v!=fa)dfs1(e[i].v,u);
	circle.pop_back();
}

inline void OUT(int u,int v)
{
	fflush(stdout);
	printf("N "); goal=v;
	dfs1(u,0);
}

inline pair<int,int> Find_twosets(vector<int> have,vector<int> rest)
{
	int Temp=query(rest);
	vector<int>tmp;
	while((int)have.size()>1)
	{
		tmp.clear();
		REP(j,0,(have.size()>>1)-1)tmp.push_back(have[j]);
			
		if(twosets(tmp,rest,-1,Temp))have=tmp;
		else {
			tmp.clear();
			REP(j,(have.size()>>1),have.size()-1)tmp.push_back(have[j]);
			have=tmp;
		}
	}

	while((int)rest.size()>1)
	{
		tmp.clear();
		REP(j,0,(rest.size()>>1)-1)tmp.push_back(rest[j]);
		if(twosets(have,tmp,-1,-1))rest=tmp;
		else {
			tmp.clear();
			REP(j,(rest.size()>>1),rest.size()-1)tmp.push_back(rest[j]);
			rest=tmp;
		}
	}
	return make_pair(have[0],rest[0]);
}

inline void doing()
{
	now.push_back(1); vis[1]=1;
	vector<int>rest,have,tmp,tmp1;
	while((int)now.size()<n)
	{
		rest.clear(); have.clear();
		REP(i,1,n)if(!vis[i])rest.push_back(i);else have.push_back(i);

		pair<int,int> x=Find_twosets(have,rest);
		addedge(x.first,x.second); addedge(x.second,x.first);
		now.push_back(x.second); vis[x.second]=1;
	}
	dfs(1,0);
	if(query(odd))
	{
		while((int)odd.size()>1)
		{
			tmp.clear();
			REP(j,0,(odd.size()>>1)-1)tmp.push_back(odd[j]);
			
			if(query(tmp))odd=tmp;
			else {
				tmp1.clear();
				REP(j,(odd.size()>>1),odd.size()-1)tmp1.push_back(odd[j]);
				if(query(tmp1))odd=tmp1;
				else {
					pair<int,int>x=Find_twosets(tmp,tmp1);
					OUT(x.first,x.second);
				}
			}
		}
	}
	else if(query(even))
	{
		while((int)even.size()>1)
		{
			tmp.clear();
			REP(j,0,(even.size()>>1)-1)tmp.push_back(even[j]);
			
			if(query(tmp))even=tmp;
			else {
				tmp1.clear();
				REP(j,(even.size()>>1),even.size()-1)tmp1.push_back(even[j]);
				if(query(tmp1))even=tmp1;
				else {
					pair<int,int>x=Find_twosets(tmp,tmp1);
					OUT(x.first,x.second);
				}
			}
		}
	}else
	{
		printf("Y %d\n",(int)odd.size());
		for(int t:odd)printf("%d ",t);puts("");
	}
}

int main()
{
	init();
	doing();
	return 0;
}