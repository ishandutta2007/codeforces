#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
using std::cin;using std::cerr;
using std::max;using std::min;
#define N 1005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,A[N],mark[N],G;
int gcd(int x,int y) {return y?gcd(y,x%y):x;}
void clear()
{
	G=0;
	for(int i=1;i<=n;i++) mark[i]=0;
}
int main()
{
	for(scanf("%d",&T);T--;puts(""),clear())
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		for(int i=1,Max,tmp,id;i<=n;i++)
		{
			Max=0;
			for(int j=1;j<=n;j++) if(!mark[j])
			{
				tmp=gcd(G,A[j]);
				if(tmp>Max) Max=tmp,id=j;
			}
			printf("%d ",A[id]),mark[id]=1,G=Max;
		}
	}
	return 0;
}