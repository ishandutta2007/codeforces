#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define min(q,w) ((q)>(w)?(w):(q))
#define max(q,w) ((q)<(w)?(w):(q))
using namespace std;
typedef long long LL;
const int N=1500,INF=2147483640;
const LL INFL=9223372036854775800;
int m,n,ans;
int main()
{
	// freopen("!.in","r",stdin);
//	freopen(".out","w",stdout);
	int q,w;
	scanf("%d%d",&n,&m);
	ans=1;
	fo(i,1,n)
	{
		ans<<=1;
		if(ans>m){printf("%d\n",m);return 0;}
	}
	printf("%d\n",m%ans);
	return 0;
}