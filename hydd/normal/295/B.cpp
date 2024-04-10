/*********************************************************************
 * Source
 * ProblemCF295B
 * Authorhydd
 * Date2020/9/8
 * EncodingSimplified Chinese (GB2312)
*********************************************************************/
#include<cstdio>
#include<algorithm>
//#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
typedef long long ll;
int n,dis[510][510],a[510];
bool vis[510]; ll ans[510];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&dis[i][j]);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int t=n;t>=1;t--){
		int k=a[t]; vis[k]=true;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				if (vis[i]&&vis[j]) ans[t]+=dis[i][j];
			}
	}
	for (int i=1;i<=n;i++) printf("%lld ",ans[i]);
	return 0;
}