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

const int maxn=2e5+20;

int n,m;
ll a[maxn],b[maxn];

inline void init()
{
	n=read();m=read();
	REP(i,1,n)scanf("%lld",a+i);
}

struct node {
	int x,op;
};
node c[maxn];
inline bool operator <(node a,node b){ return a.x>b.x;}
int tot;

ll ans[5];
ll tag[5];

inline void calc(int xs)
{
	if(!xs)return;
	if(tag[2] || tag[4]>=2)ans[1]+=xs,ans[2]+=xs;
	else {
		int win=tag[3]+tag[4]&1;

		if(tag[4] && !win)ans[1]+=xs,ans[2]+=xs;
		else if(tag[4])ans[3]+=xs<<1;
		else if(win)ans[3]+=xs<<1;
		else ans[4]+=xs<<1;
	}
}

inline void doing()
{
	REP(t,2,m<<1)
	{
		int lim=t-1>>1,lim2=max(1,t-m);
		int tot=0;
		REP(i,1,n)
		{
			int x=a[i]%t;
			//if(lim>x)c[++tot]=(node){lim,1},c[++tot]=(node){x,-1};
			if(min(x,t-x-1))c[++tot]=(node){min(x,t-x-1),2};
			if(lim>max(t-x-1,(x>>1)))c[++tot]=(node){lim,3},c[++tot]=(node){max(t-x-1,x>>1),-3};
			if((x>>1)>t-x-1)c[++tot]=(node){x>>1,4},c[++tot]=(node){t-x-1,-4};
		}
		sort(c+1,c+tot+1);
		memset(tag,0,sizeof(tag));
		int lst=lim;
		REP(i,1,tot)
		{
			if(c[i].x<lim2)break;
			calc(lst-c[i].x);
			int op=c[i].op;
			if(op<0)tag[-op]--;
			else tag[op]++;
			lst=c[i].x;
		}
		calc(lst-lim2+1);
	}
	REP(t,1,m)
	{
		int res=0;
		REP(i,1,n)res^=(a[i]/t)&1;
		if(res)ans[3]++; else ans[4]++;
	}
	REP(i,1,4)printf("%lld ",ans[i]);
}

int main()
{
	init();
	doing();
	return 0;
}