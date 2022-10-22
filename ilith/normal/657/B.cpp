#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(rgi i=a,i##i=b;i>=i##i;--i)
using namespace std;
typedef long long ll;
const int N=400010;
ll n,k,a[N],b[N],M,ans;
signed main(){
	scanf("%d%d",&n,&k),M=n;
	FOR(i,0,n)scanf("%lld",a+i),b[i]=a[i];
	FOR(i,0,n){
		a[i+1]+=a[i]/2,a[i]%=2;
		if(M==n&&a[i])M=i;
	}
	ROF(i,n,0){
		a[i]+=a[i+1]*2,a[i+1]=0;
		if(abs(a[i])>=100*k)break;
		ll cg=abs(a[i]-b[i]);
		if(i<=M&&cg<=k&&(i!=n||cg))++ans;
	}
	printf("%lld",ans);
	return 0;
}