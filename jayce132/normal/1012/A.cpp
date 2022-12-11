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
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=2e5+20;

int a[maxn];

int main()
{
	int n=read();
	REP(i,1,2*n)a[i]=read();
	sort(a+1,a+2*n+1);
	ll ans=1e18;
	ans=min(ans,(ll)(a[n]-a[1])*(a[2*n]-a[n+1]));
	REP(i,2,n)ans=min(ans,(ll)(a[i+n-1]-a[i])*(a[2*n]-a[1]));
	cout<<ans<<endl;
	return 0;
}