#include<bits/stdc++.h>
#define pbk push_back
#define FOR(i,a,b) for(int i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(int i=a,i##i=b;i>=i##i;--i)
using namespace std;
typedef long long ll;
const int N=4e5+7;
int T,n,a[N];
ll ans=1e18,b[N],su,ct;
signed main(){
//	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		FOR(i,1,n)scanf("%d",a+i);
		FOR(i,1,n){
			b[i]=su=0;
			FOR(j,i+1,n){
				ct=(b[j-1]+a[j])/a[j];
				su+=ct,b[j]=ct*a[j];
			}
			ROF(j,i-1,1){
				ct=(b[j+1]+a[j])/a[j];
				su+=ct,b[j]=ct*a[j];
			}
			ans=min(ans,su);
		}
		printf("%lld",ans);
//	}
	return 0;
}