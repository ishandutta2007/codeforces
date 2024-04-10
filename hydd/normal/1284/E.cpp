#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef long double ldb;
const ldb pi=acos(-1.0L);
const ldb eps=1e-19;
int n;
ll a[110000],b[110000];
ldb d[110000];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld%lld",&a[i],&b[i]);
	ll ans=(ll)n*(n-1)*(n-2)*(n-3)*(n-4)/24;
	for (int i=0;i<n;i++){
		int m=0;
		for (int j=0;j<n;j++){
			if (i==j) continue;
			ldb x=a[j]-a[i],y=b[j]-b[i];
			d[m++]=atan2(y,x);
		}
		sort(d,d+m);
		int now=0;
		for (int j=0;j<m;j++){
			while (now<j+m){
				ldb ang=d[now%m]-d[j];
				if (ang<0) ang+=2*pi;
				if (ang<pi+eps) now++;
				else break;
			}
			ll tmp=now-j-1;
			ans-=tmp*(tmp-1)*(tmp-2)/6;
		}
	}
	printf("%lld\n",ans);
	return 0;
}