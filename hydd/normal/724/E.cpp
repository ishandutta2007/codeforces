/*********************************************************************
 * Sourceysy
 * ProblemCF724E
 * Authorhydd
 * Date2020/9/2
 * EncodingSimplified Chinese (GB2312)
*********************************************************************/
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF=1ll<<60;
int n,c;
ll p[11000],s[11000],f[2][11000],ans;
int main(){
	scanf("%d%d",&n,&c);
	for (int i=1;i<=n;i++) scanf("%lld",&p[i]);
	for (int i=1;i<=n;i++) scanf("%lld",&s[i]);
	ans=INF;
	for (int i=1;i<=n;i++){
		int now=i&1;
		for (int j=0;j<=n;j++) f[now][j]=INF;
		f[now][0]=f[now^1][0]+p[i];
		for (int j=1;j<=i;j++) f[now][j]=min(f[now^1][j-1]+s[i],f[now^1][j]+p[i]+1ll*j*c);
	}
	for (int i=0;i<=n;i++) ans=min(ans,f[n&1][i]);
	printf("%lld\n",ans);
	return 0;
}