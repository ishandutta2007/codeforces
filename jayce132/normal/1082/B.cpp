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

const int maxn=1e5+20;

int n;
char str[maxn];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
#endif
	n=read();
	cin>>(str+1);str[n+1]='S';
	int ans=0,G=0,lst=0,GG=0;
	REP(i,1,n+1)if(str[i]=='S')
	{
		chkmax(ans,G);
		chkmax(ans,lst+G+1);
		lst=G;
		G=0;
	}else G++,GG++;
	chkmin(ans,GG);
	cout<<ans<<endl;
	return 0;
}