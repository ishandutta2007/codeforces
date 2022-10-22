#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF=1ll<<60;
int n,p[510000],sum[2][510000];
int tmp1[510000],tmp2[510000];
ll dp[60][510000],c1,c2,c3,p1,p2,m;
ll sta,a[510000];
/*bool cmp(int x,int y){
	return (a[x]&sta)<(a[y]&sta);
}*/
int main(){
//	freopen("equal.in","r",stdin);
//	freopen("equal.out","w",stdout);
	scanf("%d",&n);
//	scanf("%lld%lld%lld%lld%lld%lld",&c1,&c2,&c3,&p1,&p2,&m);
//	scanf("%lld%lld",&a[1],&a[2]);
//	for (int i=3;i<=n;i++) a[i]=(a[i-1]%p1*c1%m+a[i-2]%p2*c2%m+c3)%m;
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) a[i]=a[n]-a[i];
	for (int w=0;w<=58;w++)
		for (int i=0;i<=n;i++)
			dp[w][i]=INF;
	for (int i=1;i<=n;i++) p[i]=i;
	dp[0][0]=0;
	for (int w=0;w<58;w++){
		sta=(1ll<<w)-1;
//		sort(p+1,p+n+1,cmp);
		for (int i=1;i<=n;i++){
			sum[0][i]=sum[0][i-1];
			sum[1][i]=sum[1][i-1];
			sum[(a[p[i]]>>w)&1][i]++;
		}
		for (int i=0;i<=n;i++){
			int tmp=(sum[0][n]-sum[0][n-i])+sum[1][n-i];
			int sta=sum[1][n]-sum[1][n-i];
			dp[w+1][sta]=min(dp[w+1][sta],dp[w][i]+tmp);
		}
		for (int i=0;i<=n;i++){
			int tmp=(sum[1][n]-sum[1][n-i])+sum[0][n-i];
			int sta=n-sum[0][n-i];
			dp[w+1][sta]=min(dp[w+1][sta],dp[w][i]+tmp);
		}
		int cnt1=0,cnt2=0;
		for (int i=1;i<=n;i++)
			if ((a[p[i]]>>w)&1) tmp1[++cnt1]=p[i];
			else tmp2[++cnt2]=p[i];
		int k=0;
		for (int i=1;i<=cnt2;i++) p[++k]=tmp2[i];
		for (int i=1;i<=cnt1;i++) p[++k]=tmp1[i];
	}
	printf("%lld\n",dp[58][0]);
	return 0;
}