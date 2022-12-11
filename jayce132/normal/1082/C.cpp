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
#include<cassert>
#include<vector>
using namespace std;
#define int ll
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}


const int maxn=5e5+20;

int n,m;
vector<int>to[maxn];

inline void init()
{
	n=read();m=read();
	REP(i,1,n)
	{
		int x=read(),y=read();
		to[x].push_back(y);
	}
	REP(x,1,m)sort(to[x].begin(),to[x].end(),[](int a,int b){ return a>b;});
}

ll ans[maxn];

inline void doing()
{
	REP(i,1,m)
	{
		REP(j,1,(ll)to[i].size()-1)to[i][j]+=to[i][j-1];
		REP(j,0,(ll)to[i].size()-1)if(to[i][j]>0)ans[j+1]+=to[i][j];
	}
	ll Ans=0;
	REP(j,1,n)chkmax(Ans,ans[j]);
	cout<<Ans<<endl;
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}