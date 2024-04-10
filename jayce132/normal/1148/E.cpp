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

const int maxn=3e5+20;

struct node {
	int x,id;
};
node a[maxn];

int n,s[maxn],t[maxn];

inline void init()
{
	n=read();
	REP(i,1,n)s[i]=read(),a[i]=(node){s[i],i};
	REP(i,1,n)t[i]=read();
	sort(t+1,t+n+1);
	sort(a+1,a+n+1,[](node a,node b){ return a.x<b.x;});
	REP(i,1,n)a[i].x-=t[i];
}

struct OUT {
	int i,j,d;
};

vector<OUT>ans;

inline void doing()
{
	ll s=0;
	REP(i,1,n)
	{
		s+=a[i].x;
		if(s>0)puts("NO"),exit(0);
	}
	if(s)puts("NO"),exit(0);
	stack<int>stac;
	REP(i,1,n)
	{
		if(a[i].x<0)stac.push(i);
		else if(a[i].x>0){
			while(1)
			{
				int j=stac.top();
				int now=min(a[i].x,-a[j].x);
				a[i].x-=now; a[j].x+=now;
				ans.push_back((OUT){a[j].id,a[i].id,now});
				if(a[j].x==0)stac.pop();
				if(a[i].x==0)break;
			}
		}
	}
	puts("YES");
	printf("%d\n",SZ(ans));
	for(OUT x:ans)
		printf("%d %d %d\n",x.i,x.j,x.d);
	
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}