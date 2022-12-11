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

const int maxn=4e5+20;
const double inf=1e20;

int n,t,q;

int p[maxn];
int a[maxn];
int now[maxn];
double profit[maxn],profit1[maxn];

inline int Max(int x,int y){ return profit[x]<profit[y]?y:x;}
inline int Min1(int x,int y){ return profit1[x]>profit1[y]?y:x;}

struct node {
	int id,id1;
	inline void Merge(node lc,node rc) {
		id=Max(lc.id,rc.id);
		id1=Min1(lc.id1,rc.id1);
	}
};
node c[(1<<20)+20];

#define lc (o<<1)
#define rc (o<<1|1)
#define left lc,l,mid
#define right rc,mid+1,r

void make_tree(int o,int l,int r)
{
	if(l==r)return c[o].id=l,c[o].id1=l,void();
	int mid=l+r>>1;
	make_tree(left);
	make_tree(right);
	c[o].Merge(c[lc],c[rc]);
}

void update(int x,int o,int l,int r)
{
	if(l==r)return;
	int mid=l+r>>1;
	if(x<=mid)update(x,left);
	else update(x,right);
	c[o].Merge(c[lc],c[rc]);
}

double ans;

inline double Profit(int i,int x){ return x<a[i]?x>=0?1.0*p[i]*a[i]/(1ll*(a[i]+x)*(a[i]+x+1)):1e20:-1e20;}
inline double Value(int i,int x){ return p[i]-1.0*p[i]*a[i]/(a[i]+x);}

inline void Check()
{
	while(t)
	{
		int i=c[1].id;
		if(now[i]==a[i])break;
		ans+=profit[i];
		now[i]++;
		profit[i]=Profit(i,now[i]);
		profit1[i]=Profit(i,now[i]-1);
		update(i,1,1,n);
		t--;
	}
}

inline void Check1(int i)
{
	if(now[i])
	{
		double Pft=Profit(i,now[i]-1);
		int j=c[1].id;
		if(Pft<profit[j])
		{
			now[i]--; ans-=Pft;
			now[j]++; ans+=profit[j];
			profit[i]=Profit(i,now[i]); profit1[i]=Profit(i,now[i]-1);
			profit[j]=Profit(j,now[j]); profit1[j]=Profit(j,now[j]-1);
			update(i,1,1,n); update(j,1,1,n);
		}//else break;
	}
}

inline void Check2(int i)
{
	if(now[i]<a[i])
	{
		double Pft=Profit(i,now[i]);
		int j=c[1].id1;
		if(Pft>profit1[j])
		{
			now[i]++; ans+=Pft;
			now[j]--; ans-=profit1[j];
			profit[i]=Profit(i,now[i]); profit1[i]=Profit(i,now[i]-1);
			profit[j]=Profit(j,now[j]); profit1[j]=Profit(j,now[j]-1);
			update(i,1,1,n); update(j,1,1,n);
		}//else break;
	}
}

inline void init()
{
	n=read();t=read();q=read();
	REP(i,1,n)p[i]=read();
	REP(i,1,n)a[i]=read();
	REP(i,0,n)profit[i]=Profit(i,0),profit1[i]=Profit(i,-1);
	make_tree(1,1,n);
	Check();
}

inline void doing()
{
	//cerr<<(double)clock()/CLOCKS_PER_SEC<<endl;
	while(q--)
	{
		int op=read(),i=read();
		if(op==1)
		{
			ans-=Value(i,now[i]);
			a[i]++;
			ans+=Value(i,now[i]);
			profit[i]=Profit(i,now[i]);
			profit1[i]=Profit(i,now[i]-1);
			update(i,1,1,n);
			Check1(i);Check2(i);
			Check();
		}else
		{
			ans-=Value(i,now[i]);
			a[i]--; if(now[i]>a[i])now[i]--,t++;
			ans+=Value(i,now[i]);
			profit[i]=Profit(i,now[i]);
			profit1[i]=Profit(i,now[i]-1);
			update(i,1,1,n);
			Check1(i);Check2(i);
			Check();
		}
		printf("%.10lf\n",ans);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF626G.in","r",stdin);
	freopen("CF626G.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}