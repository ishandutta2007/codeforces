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

inline void init()
{
	int n=read();
	REP(i,1,26)if((1<<i)-1>=n)
	{
		if((1<<i)-1>n)return printf("%d\n",(1<<i)-1),void();
		else {
			for(int j=2;j*j<=n;j++)
				if(n%j==0)
				{
					printf("%d\n",n/j);
					return;
				}
			printf("%d\n",1);
			return;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
#endif
	int q=read();
	while(q--)
	{
		init();
	}
	return 0;
}