#include<list>
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
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=1e6+20;

int n,a[maxn];
vector<int>id[maxn];

inline bool check()
{
	if(a[1] && a[2*n-1] && a[1]!=a[2*n-1])return 0;
	REP(i,1,n)if(!id[i].empty())
	{
		int st=id[i].front();
		for(int v:id[i])if(v-st&1)return 0;
	}
	/*int mx=0;
	REP(i,1,2*n-1)if(a[i])
	{
		int R=id[a[i]].back();
		if(i>mx && R>mx)mx=R;
		else if(i<mx && R>mx)return 0;
		}*/
	return 1;
}

int st[maxn],top;

inline int NewNode()
{
	if(top)return st[top--];
	else {
		puts("no"),exit(0);
	}
}

inline void init()
{
	n=read();REP(i,1,2*n-1)a[i]=read(),a[i]?id[a[i]].push_back(i),0:0;
	if(!check())
	{
		puts("no"),exit(0);
	}
	REP(i,1,n)if(id[i].empty())st[++top]=i;
	a[1]=a[2*n-1]=a[1]|a[2*n-1];

	if(!a[1] && !a[2*n-1])
	{
		REP(i,2,2*n-2)if(a[i])
		{
			if(~i-1&1)
			{
				a[1]=a[2*n-1]=a[i];
				break;
			}else i=id[a[i]].back();
		}
		if(!a[1])
		{
			a[1]=a[2*n-1]=NewNode();
		}
	}

	REP(i,1,n)id[i].clear();
	REP(i,1,2*n-1)if(a[i])id[a[i]].push_back(i);
}

#define pri pair<int,int>
#define mkr(a,b) make_pair(a,b)
#define fi first
#define se second

void solve(int root,int l,int r)
{
	list<pri >v;
	REP(i,l,r)
	{
		if(!a[i] || (int)id[a[i]].size()==1)v.push_back(mkr(a[i],i));
		else {
			REP(j,1,id[a[i]].size()-1)
			{
				if(id[a[i]][j]>r)puts("no"),exit(0);
				solve(a[i],id[a[i]][j-1]+1,id[a[i]][j]-1);
			}
			i=id[a[i]].back();
			v.push_back(mkr(a[i],i));
		}
	}

	list<pri >::iterator it,itt,ittt;
	
	int t=0;
	for(it=v.begin();it!=v.end();it++)t+=it->fi>0;
	if(t*2>v.size()+1)
	{
		puts("no"),exit(0);
	}
	for(it=v.begin();it!=v.end();it)
	{
		if(it==v.begin()){it++;continue;}
		if(!it->fi){it++;continue;}
		itt=it; itt--;
		ittt=it; ittt++;
		if(ittt==v.end())break;
		if((itt->fi>0) + (ittt->fi>0)==1)
		{
			(itt->fi?a[ittt->se]:a[itt->se])=itt->fi | ittt->fi;
			*it=mkr(itt->fi|ittt->fi,0);
			v.erase(itt);v.erase(ittt);
			if(it!=v.begin())it--;
		}else it++;
	}

	
	  for(it=v.begin();it!=v.end();it++)
	  {
	  itt=it;itt++;
	  if(itt==v.end())continue;
	  ittt=itt;ittt++;
	  if(ittt==v.end())continue;
	  assert(!(!it->fi && itt->fi && ittt->fi));
	  }
	
	
	for(it=v.begin();it!=v.end();)
	{
		itt=it;itt++;
		if(itt==v.end())
		{
			if(!it->fi)a[it->se]=NewNode();
			return;
		}else
		{
			ittt=itt;ittt++;
			if(it->fi && itt->fi)
			{
				a[ittt->se]=it->fi;
				*ittt=*it;
				v.erase(it); v.erase(itt);
				it=ittt;
			}
			else if(it->fi && !itt->fi)
			{
				a[itt->se]=root;
				v.erase(it); v.erase(itt);
				it=ittt;
			}
			else if(!it->fi && itt->fi)
			{
				//assert(!ittt->fi);
				a[ittt->se]=a[it->se]=NewNode();
				*ittt=mkr(a[it->se],it->se);
				v.erase(it); v.erase(itt);
				it=ittt;
			}else
			{
				a[it->se]=NewNode();
				a[itt->se]=root;
				v.erase(it); v.erase(itt);
				it=ittt;
			}
		}
	}
	assert(v.empty());
	/*
	  while(j<(int)v.size())
	  {
	  if(j+1==(int)v.size())
	  {
	  pri x=v[j++];
	  if(x.fi==0)a[x.se]=NewNode();
	  else return;
	  }
	  //else if(v.size()==2)puts("no"),exit(0);
	  else
	  {
	  pri x=v[j++];
	  pri y=v[j++];
	  pri z=v[j++];
	  if(x.fi && y.fi && z.fi)puts("no"),exit(0);
	  if(x.fi && y.fi)a[z.se]=x.fi,v[--j]=x;
	  else if(x.fi && !y.fi)a[y.se]=root,v[--j]=(z);
	  else if(!x.fi && y.fi)
	  {
	  if(!z.fi)a[x.se]=a[z.se]=NewNode(),v[--j]=mkr(a[x.se],x.se);
	  else a[x.se]=z.fi,v[--j]=z;
	  }else {
	  v[--j]=z;
	  a[x.se]=NewNode();
	  a[y.se]=root;
	  }
	  }
	  }
	*/
}

inline void doing()
{
	REP(j,1,id[a[1]].size()-1)solve(a[1],id[a[1]][j-1]+1,id[a[1]][j]-1);
	puts("yes");
	REP(i,1,2*n-1)printf("%d ",a[i]);puts("");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("Euler.in","r",stdin);
	freopen("Euler.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}