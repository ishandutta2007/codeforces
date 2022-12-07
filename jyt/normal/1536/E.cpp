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
#define N 2005
#define mod 1000000007
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,m,cnt,flag;char s[N];
int Pow(int x,int y) {int res=1;for(;y;x=(ll)x*x%mod,y>>=1) if(y&1) res=(ll)res*x%mod;return res;}
int main()
{
	for(scanf("%d",&T);T--;flag=cnt=0)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=m;j++) flag|=s[j]=='0',cnt+=s[j]=='#';
		}
		printf("%d\n",Pow(2,cnt)-(!flag));
	}
	return 0;
}