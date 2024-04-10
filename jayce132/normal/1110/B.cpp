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
	int n=read(); read(); int k=read();
	REP(i,1,n)a[i]=read();
	k=n-k;
	DREP(i,n,2)a[i]-=a[i-1];
	sort(a+2,a+n+1);
	int ans=0;
	REP(i,2,k+1)ans+=a[i];
	ans+=n-k;
	printf("%d\n",ans);
	return 0;
}