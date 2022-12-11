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

const int maxn=1e6+20;

int p[maxn],vis[maxn],n2;

int n;

vector<pair<int,int> >ans;

inline void Swap(int i,int j)
{
	if(i>j)swap(i,j);
	if(abs(i-j)>=n2)
	{
		ans.push_back(mkr(i,j));
	}
	else if(max(i,j)+n2<=n || min(i,j)>n2 )
	{
		int x;
		if(max(i,j)+n2<=n)x=n;
		else x=1;
		ans.push_back(mkr(i,x));
		ans.push_back(mkr(j,x));
		ans.push_back(mkr(i,x));
	}else
	{
		ans.push_back(mkr(i,n));
		ans.push_back(mkr(1,j));
		ans.push_back(mkr(1,n));
		ans.push_back(mkr(i,n));
		ans.push_back(mkr(1,j));
	}
}

int main()
{
	n=read();n2=n+1>>1;
	REP(i,1,n)p[i]=read();
	REP(i,1,n)if(!vis[i])
	{
		for(int j=i;!vis[j];j=p[j])
			(p[j]!=i?Swap(i,p[j]),0:0),vis[j]=1;
	}
	printf("%d\n",SZ(ans));
	for(pair<int,int> x:ans)printf("%d %d\n",x.fi,x.se),swap(p[x.fi],p[x.se]);
	//REP(i,1,n)cerr<<p[i]<<" ";cerr<<endl;
	return 0;
}