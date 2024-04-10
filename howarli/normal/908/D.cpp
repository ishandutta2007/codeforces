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
const int N=1500,mo=1e9+7;
const LL eni=500000004;
int m,n;
LL pa,pb;
LL f[N][N],ans;
LL f1[N][N];
LL ksm(LL q,int w)
{
	LL ans=1;
	for(;w;w>>=1,q=q*q%mo)if(w&1)ans=ans*q%mo;
	return ans;
}
int main()
{
	// freopen("!.in","r",stdin);
//	freopen(".out","w",stdout);
	int q,w;
	scanf("%d%I64d%I64d",&n,&pa,&pb);
	q=pa+pb;
	pa=pa*ksm(q,mo-2)%mo;
	pb=pb*ksm(q,mo-2)%mo;
	f[0][1]=1;
	fo(i,0,n-1)
	{
		fo(j,1,n-1)
		{
			if(i+j>=n)
			{
				ans=(ans+((LL)i+j)*pb%mo*f[i][j])%mo;
			}else f[i+j][j]=(f[i+j][j]+pb*f[i][j])%mo;
			f[i][j+1]=(f[i][j+1]+pa*f[i][j])%mo;
		}
		ans=(ans+f[i][n]*((LL)i+(LL)n+pa*ksm(mo+1-pa,mo-2)%mo))%mo;
	}
	printf("%I64d\n",ans);
	return 0;
}