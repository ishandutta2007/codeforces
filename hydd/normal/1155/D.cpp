/*********************************************************************
 * Source
 * ProblemCF1155D
 * Authorhydd
 * Date2020/9/8
 * EncodingSimplified Chinese (GB2312)
*********************************************************************/
#include<cstdio>
#include<algorithm>
//#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
typedef long long ll;
const int maxn=1e6+9;
int n,k,x;
ll f[1100000][3];
int main(){
	scanf("%d%d",&n,&k); ll ans=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		f[i][0]=max(f[i-1][0]+x,0ll);
		f[i][1]=max(f[i-1][1]+1ll*x*k,f[i][0]);
		f[i][2]=max(f[i-1][2]+x,f[i][1]);
		ans=max(ans,f[i][2]);
	}
	printf("%lld\n",ans);
	return 0;
}