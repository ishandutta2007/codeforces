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

const int maxn=1e3+20;

int n,p1[maxn],p2[maxn];
int id1[maxn],id2[maxn];

inline void init()
{
	n=read();
	REP(i,1,n)p2[i]=read(),id2[p2[i]]=i;
	REP(i,1,n)p1[i]=read(),id1[p1[i]]=i;
}

vector<pair<pair<int,int>,pair<int,int> > >ans;

inline void doing()
{
	REP(i,1,n)
	{
		int x=id1[i],y=id2[i];
		if(x==i && y==i)continue;
		ans.push_back(mkr(mkr(i,x),mkr(y,i)));
		p1[x]=p1[i]; p2[y]=p2[i];
		id1[p1[x]]=x; id2[p2[y]]=y;
	}
	printf("%d\n",SZ(ans));
	for(pair< pair< int, int > , pair<int,int> > x:ans)
		printf("%d %d %d %d\n",x.fi.fi,x.fi.se,x.se.fi,x.se.se);
}

int main()
{
	init();
	doing();
	return 0;
}