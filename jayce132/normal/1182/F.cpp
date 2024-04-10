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

#define int ll

const int maxn=2e5+20;

int a,b,p,q,len;

struct node {
	int pos,id;
};

node x[maxn],y[maxn];

inline bool cmp (node a,node b){ return a.pos==b.pos?a.id<b.id:a.pos<b.pos;}

inline void init()
{
	a=read();b=read();p=read()<<1;q=read()<<1;
	len=b-a+1;
	int ad=(ll)p*a%q,S=sqrt(len),q2=q>>1;
	p%=q;
	int ans=q+1,ansid=0;
	REP(i,0,S-1)x[i].id=i,x[i].pos=((ll)i*p+ad)%q;
	REP(i,0,S-1)y[i].id=i*S,y[i].pos=(ll)i*S*p%q;
	sort(x,x+S,cmp);

	int ys=0;
	sort(y,y+S,cmp);
	REP(i,1,S-1)if(y[i].pos==y[ys].pos);
	else y[++ys]=y[i];
	ys++;
	reverse(y,y+ys);
	int j=0;
	REP(i,0,S-1)
	{
		while(j<ys && x[i].pos+y[j].pos>q2)j++;
		if(j<ys)
		{
			int t=q2-(x[i].pos+y[j].pos),ID=x[i].id+y[j].id;
			if(t<ans || (t==ans && ansid>ID))ans=t,ansid=ID;
		}
		if(j)
		{
			int J=j-1;
			int t=x[i].pos+y[J].pos-q2,ID=x[i].id+y[J].id;
			if(t<ans || (t==ans && ansid>ID))ans=t,ansid=ID;
		}
	}

	j=0;
	REP(i,0,S-1)
	{
		while(j<ys && x[i].pos+y[j].pos>q2+q)j++;
		if(j<ys && x[i].pos+y[j].pos>=q)
		{
			int t=q2+q-(x[i].pos+y[j].pos),ID=x[i].id+y[j].id;
			if(t<ans || (ans==t && ansid>ID))ans=t,ansid=ID;
		}
		if(j)
		{
			int J=j-1;
			int t=x[i].pos+y[J].pos-q2-q,ID=x[i].id+y[J].id;
			if(t<0)continue;
			if(t<ans || (ans==t && ansid>ID))ans=t,ansid=ID;
		}
	}

	REP(i,S*S,len-1)
	{
		int t=((ll)i*p+ad)%q;
		if(abs(q2-t)<ans)ans=abs(q2-t),ansid=i;
	}
	
	printf("%lld\n",ansid+a);
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("f.in","r",stdin);
	freopen("f.out","w",stdout);
#endif
	int t=read();
	while(t--)init();
	return 0;
}