#include<bits/stdc++.h>
#define pbk push_back
#define FOR(i,a,b) for(int i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(int i=a,i##i=b;i>=i##i;--i)
using namespace std;
typedef long long ll;
const int N=1e6+7,mod=998244353;
int T,n,k,a[N],b[N];
ll ans;
void solve(){
	scanf("%d%d",&n,&k),ans=1;
	FOR(i,1,n)scanf("%d",a+i),b[i]=0;
	FOR(i,n-k+1,n)if(a[i]>0){
		puts("0");
		return;
	}
	FOR(i,k+1,n)if(a[i-k]==-1)b[i]=-1;
	else if(a[i-k]==0)b[i]=0;
	else b[i]=a[i-k]+k;
	FOR(i,1,n){
		if(b[i]>=i){
			puts("0");
			return;
		}
		if(!b[i])(ans*=min(i-1,k)+1)%=mod;
		else if(b[i]==-1)(ans*=i)%=mod;
	}
	printf("%lld\n",ans);
}
signed main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}