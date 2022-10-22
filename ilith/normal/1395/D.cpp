#include <bits/stdc++.h>
using namespace std;
long long n,d,m;
long long a[200050];
long long sum[200050];
long long cnt;
long long ans;
int main(){
	cin>>n>>d>>m;
	for(long long i=1;i<=n;i++) {
		cin>>a[i];
		cnt+=(a[i]<=m);
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(long long i=0;i<=n-cnt;i++){
		if(i*(d+1)>=n-cnt&&(i-1)*(d+1)<n){
	        long long temp=n-max((i-1)*(d+1)+1,n-cnt);
	        ans=max(ans,sum[n]-sum[n-i]+sum[cnt]-sum[cnt-temp]);
		}
    }
    cout<<ans;
    return 0;
}