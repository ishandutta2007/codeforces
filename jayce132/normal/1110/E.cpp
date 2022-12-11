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

const int maxn=1e5+20;

int a[maxn],b[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E.in","r",stdin);
    freopen("E.out","w",stdout);
#endif
	int n=read();
	REP(i,1,n)a[i]=read();DREP(i,n,2)a[i]-=a[i-1];
	REP(i,1,n)b[i]=read();DREP(i,n,2)b[i]-=b[i-1];
	sort(a+2,a+n+1);sort(b+2,b+n+1);
	REP(i,1,n)if(a[i]!=b[i])puts("No"),exit(0);
	puts("Yes");
	return 0;
}