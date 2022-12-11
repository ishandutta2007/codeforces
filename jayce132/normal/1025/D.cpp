#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<map>
#include<stack>
#include<vector>
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

const int maxn=705;

bitset <705>f[maxn][maxn];
int n,a[maxn];
bool g[maxn][maxn],ojbkL[maxn][maxn],ojbkR[maxn][maxn];

inline void init()
{
	n=read();
	REP(i,1,n)a[i]=read();
	REP(i,1,n-1)REP(j,i+1,n)g[i][j]=__gcd(a[i],a[j])>1;
	REP(i,1,n)g[i][n+1]=1,g[0][i]=1;
}

inline void doing()
{
	REP(i,1,n)f[i][i][i]=1,ojbkR[i][i]=g[i][i+1],ojbkL[i][i]=g[i-1][i];
	REP(len,2,n)
	{
		REP(l,1,n-len+1)
		{
			int r=l+len-1;
			REP(k,l,r)
			{
				f[l][r][k]=1;
				if(k>l)f[l][r][k]=f[l][r][k]&ojbkR[l][k-1];
				if(k<r)f[l][r][k]=f[l][r][k]&ojbkL[k+1][r];
			}
			REP(k,l,r)ojbkR[l][r]|=f[l][r][k]&g[k][r+1];
			REP(k,l,r)ojbkL[l][r]|=f[l][r][k]&g[l-1][k];
		}
	}
	if(ojbkR[1][n])puts("Yes");
	else puts("No");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}