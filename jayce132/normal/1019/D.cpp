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
#define SZ(A) ((int)A.size())
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=2e3+20;

struct point {
	int x,y;
	point(int _x=0,int _y=0){ x=_x; y=_y;}
};
point p[maxn];

inline point operator - (point a,point b){ return point(a.x-b.x,a.y-b.y);}
inline ll cross(point a,point b){ return 1ll*b.x*a.y-1ll*a.x*b.y;}

int n; 

struct LINE {
	double ct;
	int x,y;
};
LINE ALL[maxn*maxn];
int tot;
ll S;

inline void init()
{
	n=read();cin>>S;
	REP(i,1,n)
	{
		int x=read(),y=read();
		p[i]=point(x,y);
	}
	REP(i,1,n)REP(j,1,n)if(i!=j)
	{
		int dx=p[i].x-p[j].x,dy=p[i].y-p[j].y;
		ALL[++tot]=(LINE){atan2(dy,dx),i,j};
	}
	sort(ALL+1,ALL+tot+1,[](LINE a,LINE b){ return a.ct>b.ct;});
}

int id[maxn];
int pos[maxn];

inline ll Size(int i,int j,int k)
{
	return abs(cross(p[j]-p[i],p[k]-p[i]));
}

inline void Out(int i,int j,int k)
{
	puts("Yes");
	printf("%d %d\n",p[i].x,p[i].y);
	printf("%d %d\n",p[j].x,p[j].y);
	printf("%d %d\n",p[k].x,p[k].y);
	exit(0);
}

inline void doing()
{
	REP(i,1,n)pos[i]=i;
	sort(pos+1,pos+n+1,[](int a,int b){ return p[a].y<p[b].y;});
	REP(i,1,n)id[pos[i]]=i;
	REP(th,1,tot)
	{
		int i=ALL[th].x,j=ALL[th].y;
		swap(pos[id[i]],pos[id[j]]); swap(id[i],id[j]);
		//assert(id[i]+1==id[j] || id[j]+1==id[i]);
		int l,r;
		l=1; r=min(id[i],id[j])-1;
		while(l<r)
		{
			int mid=l+r+1>>1;
			if(Size(pos[mid],i,j)>=S*2)l=mid;
			else r=mid-1;
		}
		if(pos[l] && pos[l]!=i && pos[l]!=j && Size(pos[l],i,j)==S*2)Out(pos[l],i,j);
		l=max(id[i],id[j])+1;r=n;
		while(l<r)
		{
			int mid=l+r>>1;
			if(Size(pos[mid],i,j)>=S*2)r=mid;
			else l=mid+1;
		}
		if(pos[l] && pos[l]!=i && pos[l]!=j && Size(pos[l],i,j)==S*2)Out(pos[l],i,j);
	}
	puts("No");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("large.in","r",stdin);
	freopen("large.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}