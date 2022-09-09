#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

struct pt
{
	ll x,y;
	int id;
	pt(){}
	pt(ll _x,ll _y){x=_x;y=_y;id=-1;}
};

inline bool operator <(pt a,pt b)
{
	return (a.x<b.x)||((a.x==b.x)&&(a.y<b.y));
}

inline pt operator -(pt a,pt b)
{
	return pt(a.x-b.x,a.y-b.y);
}

inline ll operator*(pt a,pt b)
{
	return a.x*b.y-a.y*b.x;
}

inline ll d(pt a)
{
	return a.x*a.x+a.y*a.y;
}

const int maxn=1505;

pt p[maxn];
pt minpsort;
int ans[maxn];
vector<int> gr[maxn];
int sz[maxn];
int n;


inline bool cmp(pt a,pt b)
{
	ll vp=(a-minpsort)*(b-minpsort);
	return (vp>0)||((vp==0)&&(d(a-minpsort)<d(b-minpsort)));
}

void getsizes(int cur,int pr)
{
	sz[cur]=1;
	for (int i=0;i<gr[cur].size();i++) if (gr[cur][i]!=pr)
	{
		getsizes(gr[cur][i],cur);
		sz[cur]+=sz[gr[cur][i]];
	}
}

void go(int cur,int pr,int l,int r)
{
	pt minp=p[l];
	for (int i=l+1;i<r;i++) minp=min(minp,p[i]);
	minpsort=minp;
// 	cout << "go " << cur << ' ' << l << ' ' << r << " at " << minp.x << ' ' << minp.y << " (" << minp.id << ")" << endl;
	sort(p+l,p+r,cmp);
	ans[minp.id]=cur;
	int curp=l+1;
	for (int i=0;i<gr[cur].size();i++) if (gr[cur][i]!=pr)
	{
// 		cout << curp << ' ' << sz[gr[cur][i]] << endl;
		go(gr[cur][i],cur,curp,curp+sz[gr[cur][i]]);
		curp+=sz[gr[cur][i]];
	}
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--,b--;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	for (int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		p[i].x=x;
		p[i].y=y;
		p[i].id=i;
	}
	getsizes(0,-1);
	go(0,-1,0,n);
	for (int i=0;i<n;i++) cout << ans[i]+1 << ' ';
	return 0;
}