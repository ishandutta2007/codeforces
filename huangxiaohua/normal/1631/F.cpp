#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,n,m,t;
ll a[1005000],res,ji,ou,x,y;
void work(){
	ll tmp=0;
	for(i=1;i<=m;i++){
		k=n+1-i;
		ji=-1e18;ou=0;
		for(j=k-m;j>=1;j-=m){
			x=max(ji+a[j],ou-a[j]);
			y=max(ou+a[j],ji-a[j]);
			ji=x;ou=y;
		}
		tmp+=max(ji-a[k],ou+a[k]);
	}
	res=max(res,tmp);
}
int main(){
    ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=n;i++)cin>>a[i];
		for(i=1,k=0;i<=m;i++){cin>>j;k=__gcd(j,k);}
		m=k;res=-1e18;
		work();
		for(i=1;i<=m;i++)a[n+1-i]*=-1;
		work();
		printf("%lld\n",res);
	}
}