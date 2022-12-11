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
#define RG register
#define REP(i,a,b) for(RG int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(RG int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(RG int i=start[(a)];i;i=e[i].next)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=1e6+20;

struct Query {
	int x,d;
	bool operator <(const Query a)const
		{
			return x<a.x;
		}
};

Query qu[maxn*2];

int n,m;

void init()
{
	n=read();m=read();
	REP(i,1,n)qu[i]=(Query){read(),-1};
	ll s=0;
	REP(i,1,m)
	{
		qu[i+n]=(Query){read(),read()};
		s+=qu[i+n].d;
	}
	sort(qu+1,qu+n+m+1);
	if(s<n){printf("-1\n");exit(0);}
	n=n+m;
}

struct node {
	ll x;int p;
	bool operator <(const node a)const
		{
			return x>a.x;
		}
};

priority_queue<node>q1;//
priority_queue<ll,vector<ll>,greater<ll> >q0;//

const ll inf=1ll<<57;
ll ans;

void doing()
{
	//q1.push((node){inf,0});
	REP(i,1,n)
	{
		if(qu[i].d==-1)
		{
			ll w=inf;
			if(!q1.empty())
			{
				w=qu[i].x+q1.top().x;
				int k=q1.top().p;q1.pop();
				if(k && qu[k].d)qu[k].d--,q1.push((node){-qu[k].x,k});
			}
			ans+=w;
			q0.push(-w-qu[i].x);
		}else
		{
			while(qu[i].d && !q0.empty() && q0.top()+qu[i].x<0)
			{
				ll w=qu[i].x+q0.top();q0.pop();
				ans+=w;qu[i].d--;
				q1.push((node){-w-qu[i].x,0});
			}
			if(qu[i].d)qu[i].d--,q1.push((node){-qu[i].x,i});
		}
	}
	printf("%lld\n",ans);
}

int main()
{
	init();
	doing();
	return 0;
}