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

const int maxn=1e5+20;

int n;
double f[maxn][120];
int a[maxn],b[maxn];

inline void init()
{
	n=read();
	REP(i,1,n)b[i]=a[i]=read(),f[i][a[i]]=1;
}

inline double C(int n,int m){ if(n<m || m<0)return 0;double res=1;REP(i,1,m)res*=(double)(n-i+1)/i;return res;}

inline void doing()
{
	int q=read();
	double res=0;
	REP(i,1,n)res+=f[i][0];
	while(q--)
	{
		int u=read(),v=read(),k=read();
		res-=f[u][0];
		REP(j,0,min(a[u],b[u]))
		{
			double tmp=f[u][j];f[u][j]=0;
			REP(i,0,min(k,j))
				f[u][j-i]+=tmp*C(j,i)*C(b[u]-j,k-i)/C(b[u],k);
		}
		b[v]+=k;b[u]-=k;
		res+=f[u][0];
		printf("%.10lf\n",res);
	}
	REP(i,1,n)
	{
		double res=0;
		//REP(j,1,a[i])res+=j*f[i][j];
		//printf("%.10lf\n",res);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("honey.in","r",stdin);
	freopen("honey.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}