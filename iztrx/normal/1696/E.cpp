#include<bits/stdc++.h>
using namespace std;
#define N 2000005
#define ll long long
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
#define mod 1000000007 
ll jc[N],ny[N],n,a[N],i,ans,j;
ll ksm(ll x,ll y){ll ret=1;for(;y;y>>=1,x=x*x%mod)if(y&1)ret=ret*x%mod;return ret;}
ll C(int n,int m){if(m>n||m<0)return 0;return jc[n]*ny[m]%mod*ny[n-m]%mod;}
int main(){
	cin>>n;
	for(i=1;i<=n+1;++i)cin>>a[i];
	for(i=jc[0]=ny[0]=1;i<=400005;++i)jc[i]=jc[i-1]*i%mod,ny[i]=ksm(jc[i],mod-2);
	for(i=1;i<=n+2;++i){
		ans+=C(i+a[i]-2,i-1);
		for(j=a[i]+1;j<=a[i-1];++j){
			ans+=C(j+i-3,j-1);
		}
	}
	cout<<max(ans-1,0ll)%mod;
}