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

const int maxn=1e5+20;

int n;
deque<int>q;

int ansx[maxn],ansy[maxn];

int na[maxn],Q;

inline void init()
{
	n=read(); Q=read();
	REP(i,1,n)q.push_back(read());
	REP(i,1,n-1)
	{
		int x,y;
		x=q.front();q.pop_front();
		y=q.front();q.pop_front();
		ansx[i]=x; ansy[i]=y;
		if(x<y)swap(x,y);
		
		q.push_front(x);
		q.push_back(y);
	}
	REP(i,1,n)na[i]=q.front(),q.pop_front();
}

inline void doing()
{
	while(Q--)
	{
		ll i,gg=i%(n-1);
		cin>>i;
		gg=i%(n-1);
		if(!gg)gg=n-1;
		if(i<=n-1)printf("%d %d\n",ansx[i],ansy[i]);
		else printf("%d %d\n",na[1],na[gg+1]);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}