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

int main()
{
	int t=read();
	while(t--)
	{
		int n=read(),x=read(),y=read(),d=read();
		int ans=1e9+1;
		if(abs(x-y)%d==0)chkmin(ans,abs(x-y)/d);
		if(abs(y-1)%d==0)chkmin(ans,(x+d-2)/d+(y-1)/d);
		if(abs(n-y)%d==0)chkmin(ans,(n-x+d-1)/d+(n-y)/d);
		if(ans<=1e9)printf("%d\n",ans);
		else puts("-1");
	}
	return 0;
}